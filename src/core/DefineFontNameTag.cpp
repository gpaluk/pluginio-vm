#include <iostream>
#include "DefineFontNameTag.h"

EX3::DefineFontNameTag::DefineFontNameTag(EX3::DataStream *ds) : EX3::Tag(ID, "DefineFontName") {
	readData(ds);
}

void EX3::DefineFontNameTag::readData(EX3::DataStream *ds) {
	fontId = ds->readUInt16();
	fontName = ds->readString();
	fontCopyright = ds->readString();
}