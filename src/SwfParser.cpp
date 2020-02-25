#include <iterator>
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

void EX3::SwfParser::readFromFile(const char *fileName)
{
	if (fileName) {
		ifstream inputFile (fileName, ios::binary);
		assert(inputFile);
		inputFile.unsetf(ios::skipws);

		istream_iterator<uint8_t> b(inputFile), e;
		const vector<uint8_t> data(b, e);

		uint32_t fileSize = data.size();

		// compression test
		vector<uint8_t> compressedData = vector<uint8_t>(data.begin() + 8, data.end());

		unsigned long uncompressedDataSize = (fileSize - 8);
		vector<uint8_t> uncompressedData(uncompressedDataSize);


		int err = uncompress(uncompressedData.data(), &uncompressedDataSize, compressedData.data(), compressedData.size());
		if (err != Z_OK) {
			cerr << err << endl;
			exit(1);
		}


		/*
		vector<uint8_t> decompressed;
		uncompress(data, decompressed);
		*/

		// testing
		ds = new EX3::DataStream(data);
		uint8_t sig1 = ds->readUInt8();
		uint8_t sig2 = ds->readUInt8();

		cout << sig1 << endl;
		cout << sig2 << endl;

		uint16_t sig3 = ds->readUInt16();

		//readFromRawData(data);
	}
}
