#include "ZONEDATA.h"

EX3::ZONEDATA::ZONEDATA(EX3::DataStream *ds) {
	readData(ds);
}

void EX3::ZONEDATA::readData(EX3::DataStream *ds) {
	alignmentCoordinate = ds->readFLOAT16();
	range = ds->readFLOAT16();
}

string EX3::ZONEDATA::toString() {
	return "[ZONEDATA alignmentCoordinate=" + to_string(alignmentCoordinate) + ", range=" + to_string(range) + "]";
}