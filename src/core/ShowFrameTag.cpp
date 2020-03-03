#include "ShowFrameTag.h"

EX3::ShowFrameTag::ShowFrameTag(EX3::DataStream *ds) : Tag(ID, "ShowFrame") {
	readData(ds);
}

void EX3::ShowFrameTag::readData(EX3::DataStream *ds) {
}