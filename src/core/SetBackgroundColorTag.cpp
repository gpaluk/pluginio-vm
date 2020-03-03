#include "SetBackgroundColorTag.h"

EX3::SetBackgroundColorTag::SetBackgroundColorTag(EX3::DataStream *ds) : EX3::Tag(ID, "SetBackgroundColor") {
	readData(ds);
}

void EX3::SetBackgroundColorTag::readData(EX3::DataStream *ds) {
	backgroundColor = EX3::RGB(ds);
}