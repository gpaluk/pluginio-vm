#include "DataStream.h"


EX3::DataStream::DataStream(vector<uint8_t> data) {
	this->data = data;
}

EX3::DataStream::~DataStream()
{

}

uint8_t EX3::DataStream::readUI8() {
	return read();
}

uint16_t EX3::DataStream::readUI16() {
	return (uint16_t)(read() + (read() << 8));
}

uint8_t EX3::DataStream::read() {
	bitIndex = 0;
	uint8_t ret = data[index++];

	return ret;
}

void EX3::DataStream::alignByte() {
	if (bitIndex > 0) {
		bitIndex = 0;
		// write tempByte?
		tempByte = 0;
	}
}

int EX3::DataStream::readNoBitReset() {
	int ret = data[index++];

	return ret;
}

uint64_t EX3::DataStream::readUB(unsigned nBits) {
	assert(nBits <= 56);
	if (nBits == 0)
		return 0;

	uint64_t ret = 0;
	if (bitIndex == 0) {
		tempByte = readNoBitReset();
	}
	for (unsigned bit = 0; bit < nBits; bit++) {
		int nb = (tempByte >> (7 - bitIndex)) & 1;
		ret += (nb << (nBits - 1 - bit));
		bitIndex++;
		if (bitIndex == 8) {
			bitIndex = 0;
			if (bit != nBits - 1) {
				tempByte = readNoBitReset();
			}
		}
	}

	return ret;
}

int64_t EX3::DataStream::readSB(unsigned nBits) {
	uint64_t ret = readUB(nBits);
	if (ret >> (nBits - 1)) {
		ret |= (0xFFFFFFFFFFFFFFFF >> nBits) << nBits;
	}

	return (int64_t)ret;
}