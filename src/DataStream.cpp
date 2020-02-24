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

uint64_t EX3::DataStream::read() {
	//bitIndex = 0;
	return (uint64_t)data[index++];
}

void EX3::DataStream::alignByte() {
	if (bitPos > 0) {
		bitPos = 0;
		// write tempByte?
		bitBuf = 0;
	}
}

/*
int EX3::DataStream::readNoBitReset() {
	return data[index++];
}
*/

unsigned int EX3::DataStream::readUBits(int nBits) {
	if (nBits == 0)
		return 0;
	int bitsLeft = nBits;
	int result = 0;
	if (!bitPos)
		fillBitBuf();
	int shift;
	for (shift = bitsLeft - bitPos; shift > 0; shift = bitsLeft - bitPos) {
		result |= bitBuf << shift;
		bitsLeft -= bitPos;
		fillBitBuf();
	}
	// consume part of buffer
	result |= bitBuf >> -shift;
	bitPos -= bitsLeft;
	bitBuf &= 0xff >> (8 - bitPos); // mask consumed bits
	return result;
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