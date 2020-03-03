#include "UnknownTag.h"

EX3::UnknownTag::UnknownTag(uint16_t tagId) : EX3::Tag(tagId, "Unknown") {
}

void EX3::UnknownTag::readData(EX3::DataStream *ds) {
}

string EX3::UnknownTag::getName() {
	return EX3::Tag::getName() + " (ID=" + to_string(id) + ")";
}