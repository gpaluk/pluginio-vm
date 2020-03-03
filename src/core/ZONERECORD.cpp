#include <iostream>
#include "ZONERECORD.h"

EX3::ZONERECORD::ZONERECORD(EX3::DataStream *ds) {
	readData(ds);
}

void EX3::ZONERECORD::readData(EX3::DataStream *ds) {
	uint8_t numZoneData = ds->readUInt8();
	for (int i = 0; i < numZoneData; i++) {
		zonedata.push_back(EX3::ZONEDATA(ds));
	}
	reserved = ds->readUBits(6) == 1;
	zoneMaskY = ds->readUBits(1) == 1;
	zoneMaskX = ds->readUBits(1) == 1;
}