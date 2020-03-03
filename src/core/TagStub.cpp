#include "TagStub.h"

EX3::TagStub::TagStub(uint16_t tagId, string tagName, EX3::DataStream *tagDataStream) 
	: EX3::Tag(tagId, tagName) {
	this->tagDataStream = tagDataStream;
}

EX3::TagStub::~TagStub() {
	delete tagDataStream;
}

void EX3::TagStub::readData(EX3::DataStream *ds) {
}

EX3::DataStream *EX3::TagStub::getDataStream() {
	return tagDataStream;
}