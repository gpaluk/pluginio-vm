#include "DefineFontAlignZonesTag.h"

EX3::DefineFontAlignZonesTag::DefineFontAlignZonesTag(EX3::DataStream *ds) : EX3::Tag(ID, "DefineFontAlignZones") {
	readData(ds);
}

void EX3::DefineFontAlignZonesTag::readData(EX3::DataStream *ds) {
	fontId = ds->readUInt16();
	CSMTableHint = (uint8_t) ds->readUBits(2);
	reserved = (uint8_t) ds->readUBits(6) == 1;
	while (ds->available() > 0) {
		zoneTable.push_back(EX3::ZONERECORD(ds));
	}
}