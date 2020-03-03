#include "SymbolClassTag.h"

EX3::SymbolClassTag::SymbolClassTag(EX3::DataStream *ds) : EX3::Tag(ID, "SymbolClass") {
	readData(ds);
}

void EX3::SymbolClassTag::readData(EX3::DataStream *ds) {
	uint16_t numSymbols = ds->readUInt16();
	for (int i = 0; i < numSymbols; i++) {
		tags.push_back(ds->readUInt16());
		names.push_back(ds->readString());
	}
}