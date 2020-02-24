#include <iterator>
#include <fstream>
#include <vector>
//#include <zlib.h>
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


		// testing
		ds = new EX3::DataStream(data);
		uint8_t sig1 = ds->readUI8();
		uint8_t sig2 = ds->readUI8();

		cout << sig1 << endl;
		cout << sig2 << endl;

		//readFromRawData(data);
	}
}
