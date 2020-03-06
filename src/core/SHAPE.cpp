#include "SHAPE.h"

EX3::SHAPE::SHAPE(EX3::DataStream *ds, int shapeNum) {
	readData(ds, shapeNum);
}

void EX3::SHAPE::readData(EX3::DataStream *ds, int shapeNum) {
	numFillBits = (int) ds->readUBits(4);
	numLineBits = (int) ds->readUBits(4);
	shapeRecords = ds->readSHAPERECORDS(numFillBits, numLineBits, shapeNum);
}