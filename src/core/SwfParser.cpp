#include <iterator>
#include <iostream>
#include <fstream>
#include <vector>
#include <zlib.h>
#include <assert.h>
#include "SwfParser.h"

#include "Tag.h"
#include "TagStub.h"
#include "EndTag.h"
#include "UnknownTag.h"
#include "ShowFrameTag.h"
#include "SetBackgroundColorTag.h"
#include "FileAttributesTag.h"
#include "DefineFontAlignZonesTag.h"
#include "SymbolClassTag.h"
#include "DefineSceneAndFrameLabelDataTag.h"
#include "DefineFontNameTag.h"

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
	
	return magic == SWF || magic == SWC;
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
		
		readTagList();
	}
}

EX3::Tag* EX3::SwfParser::readTag() {
	uint16_t tagIdAndLength = ds->readUInt16();
	uint16_t tagId = tagIdAndLength >> 6;

	uint32_t tagLength = (uint32_t) tagIdAndLength & 0x3F;
	if (tagLength == 0x3F)
	{
		tagLength = ds->readUInt32();
	}

	if (tagLength > ds->available())
	{
		tagLength = (uint32_t) ds->available();
	}

	EX3::DataStream *tagDataStream = new EX3::DataStream(ds->readBytes(tagLength));
	EX3::TagStub *ret = new EX3::TagStub(tagId, "UnresolvedTag", tagDataStream);

	return resolveTag(ret);
}

EX3::Tag* EX3::SwfParser::resolveTag(EX3::TagStub *t) {
	EX3::Tag *ret;

	switch (t->getId()) {
		case 0:
			ret = new EX3::EndTag(t->getDataStream());
			break;
		case 1:
			ret = new EX3::ShowFrameTag(t->getDataStream());
			break;
		case 9:
			ret = new EX3::SetBackgroundColorTag(t->getDataStream());
			break;
		case 69:
			ret = new EX3::FileAttributesTag(t->getDataStream());
			break;
		case 73:
			ret = new EX3::DefineFontAlignZonesTag(t->getDataStream());
			break;
			/*
		case 75:
			ret = new EX3::DefineFont3Tag(t->getDataStream());
			break;
			*/
		case 76:
			ret = new EX3::SymbolClassTag(t->getDataStream());
			break;
			/*
		case 82:
			ret = new EX3::DoABCDefineTag(t->getDataStream());
			break;
		*/
		case 86:
			ret = new EX3::DefineSceneAndFrameLabelDataTag(t->getDataStream());
			break;
		case 88:
			ret = new EX3::DefineFontNameTag(t->getDataStream());
			break;
		default:
			ret = new EX3::UnknownTag(t->getId());
	}
	delete t;

	return ret;
}

void EX3::SwfParser::readTagList() {
	
	vector<EX3::Tag*> tagList;
	EX3::Tag *t;

	while (ds->available() > 0) {
		t = readTag();
		if (t == NULL)
			break;

		cout << t->getName() << endl;
		tagList.insert(tagList.end(), t);
	};
}