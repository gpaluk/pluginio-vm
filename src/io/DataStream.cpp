#include "DataStream.h"

EX3::DataStream::DataStream(vector<uint8_t> data) {
	this->data = data;
}

EX3::DataStream::~DataStream()
{
	
}

uint8_t EX3::DataStream::readUInt8() {
	return read();
}

uint16_t EX3::DataStream::readUInt16() {
	return read() | read()<<8;
}

uint32_t EX3::DataStream::readUInt32() {
	return read() | read()<<8 
	 | read()<<16 | read()<<24;
}

uint64_t EX3::DataStream::readUInt64() {
	return read() | read()<<8 
	 | read()<<16 | read()<<24 
	 | read()<<32 | read()<<40 
	 | read()<<48 | read()<<56;
}

int8_t EX3::DataStream::readInt8() {
	return read();
}

int16_t EX3::DataStream::readInt16() {
	return read() | read()<<8;
}

int32_t EX3::DataStream::readInt32() {
	return read() | read()<<8
	 | read()<<16 | read()<<24;
}

int64_t EX3::DataStream::readInt64() {
	return read() | read()<<8
	 | read()<<16 | read()<<24 
	 | read()<<32 | read()<<40 
	 | read()<<48 | read()<<56;
}

int64_t EX3::DataStream::read() {
	bitPos = 0;
	return data[pos++];
}

void EX3::DataStream::alignByte() {
	if (bitPos > 0) {
		bitPos = 0;
		// write tempByte?
		bitBuf = 0;
	}
}

int EX3::DataStream::readNoBitReset() {
	return data[pos++];
}

void EX3::DataStream::skipHeader() {
	unsigned int nBits = readUBits(5);
	readUBits(nBits);
	readUBits(nBits);
	readUBits(nBits);
	readUBits(nBits);

	pos += 4;
}

unsigned int EX3::DataStream::readUBits(int nBits) {
	assert(nBits <= 56);
	if (nBits == 0)
		return 0;

	uint64_t ret = 0;
	if (bitPos == 0) {
		tempByte = readNoBitReset();
	}
	for (unsigned bit = 0; bit < nBits; bit++) {
		int nb = (tempByte >> (7 - bitPos)) & 1;
		ret += (nb << (nBits - 1 - bit));
		bitPos++;
		if (bitPos == 8) {
			bitPos = 0;
			if (bit != nBits - 1) {
				tempByte = readNoBitReset();
			}
		}
	}

	return ret;
}

float EX3::DataStream::readFIXED() {
	int afterPoint = readUInt16();
	int beforePoint = readUInt16();
	float ret = ((float) ((beforePoint << 16) + afterPoint)) / 65536;
	return ret;
}

float EX3::DataStream::readFIXED8() {
	int afterPoint = read();
	int beforePoint = read();
	float ret = beforePoint + (((float) afterPoint) / 256);
	return ret;
} 

int EX3::DataStream::readBits(int nBits) {
	assert(nBits <= 32);
	int num = readUBits(nBits);
	int shift = 32 - nBits;
	return (num << shift) >> shift; // sign extend
}

void EX3::DataStream::fillBitBuf() {
	bitBuf = readUInt8();
	bitPos = 8;
}

long EX3::DataStream::available() {
	return (data.size() - pos);
}

vector<uint8_t> EX3::DataStream::readBytes(long len) {
	vector<uint8_t> ret;

	if (len <= 0)
		return ret;

	bitPos = 0;
	ret = vector<uint8_t>(data.begin() + pos, data.begin() + pos + len);
	pos += len;

	return ret;
}