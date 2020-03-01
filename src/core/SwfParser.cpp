#include <iterator>
#include <iostream>
#include <fstream>
#include <vector>
#include <zlib.h>
#include <assert.h>
#include "SwfParser.h"

EX3::SwfParser::SwfParser() {
	swf = new EX3::Swf();
}

EX3::SwfParser::SwfParser(EX3::Swf *swf) {
	this->swf = swf;
}

EX3::SwfParser::~SwfParser() {
	delete swf;
	delete ds;
}

bool EX3::SwfParser::isValidSwf() {
	if (data.size() < 4)
		return false;

	uint32_t magic = data[0] | data[1]<<8 | data[2]<<16;
	
	const uint32_t SWF = 'S'<<16 | 'W'<<8 | 'F';
	const uint32_t SWC = 'S'<<16 | 'W'<<8 | 'C';
	
	return magic == SWC || magic == SWC;
}

void EX3::SwfParser::readFromFile(const char *fileName)
{
	if (fileName) {
		ifstream inputFile (fileName, ios::binary);
		assert(inputFile);
		inputFile.unsetf(ios::skipws);

		istream_iterator<uint8_t> b(inputFile), e;
		data = vector<uint8_t>(b, e);

		// testing
		EX3::DataStream *stream = new EX3::DataStream(data);
		uint8_t sig1 = stream->readUInt8(); // compression
		uint8_t sig2 = stream->readUInt8();
		uint8_t sig3 = stream->readUInt8();
		uint8_t version = stream->readUInt8();
		uint32_t fileLength = stream->readUInt32();

		switch(sig1)
		{
			case 'F': // uncompressed
				ds = stream;
			break;
			case 'C': // zlib
				vector<uint8_t> compressedData = vector<uint8_t>(data.begin() + 8, data.end());

				unsigned long uncompressedDataSize = (fileLength - 8);
				vector<uint8_t> uncompressedData(uncompressedDataSize);

				int err = uncompress(uncompressedData.data(), &uncompressedDataSize, compressedData.data(), compressedData.size());
				if (err != Z_OK) {
					cerr << err << endl;
					exit(1);
				}

				ds = new EX3::DataStream(uncompressedData);
				delete stream;
			break;
			// TODO LZMA
		}

		EX3::RECT *rect = new EX3::RECT();
		rect->nBits = ds->readUBits(5);
		rect->Xmin = ds->readUBits(rect->nBits); // xmin
        rect->Xmax = ds->readUBits(rect->nBits); // xmax
        rect->Ymin = ds->readUBits(rect->nBits); // ymin
        rect->Ymax = ds->readUBits(rect->nBits); // ymax


		printf("Valid SWF: %s\n", isValidSwf() ? "true" : "false");
		printf("Sig 1: %c\n", sig1);
		printf("Sig 2: %c\n", sig2);
		printf("Sig 3: %c\n", sig3);
		printf("Version: %u\n", version);
		printf("Filesize: %u bytes\n", fileLength);

		printf("Rect bits: %llu bits\n", rect->nBits);
		printf("Rect Xmin: %lli\n", rect->Xmin);
		printf("Rect Xmax: %lli\n", rect->Xmax);
		printf("Rect Ymin: %lli\n", rect->Ymin);
		printf("Rect Ymax: %lli\n", rect->Ymax);

		printf("Framerate: %f\n", ds->readFIXED8());
		printf("Frame count: %u\n", ds->readUInt16());

		delete rect;
		//readFromRawData(data);
	}
}
