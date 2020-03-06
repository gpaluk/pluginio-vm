#include "FOCALGRADIENT.h"

EX3::FOCALGRADIENT::FOCALGRADIENT(EX3::DataStream *ds, int shapeNum) {
	readData(ds, shapeNum);
}

void EX3::FOCALGRADIENT::readData(EX3::DataStream *ds, int shapeNum) {
	spreadMode = (int) ds->readUBits(2);
	interpolationMode = (int) ds->readUBits(2);

	int numGradients = (int) ds->readUBits(4);
	for (int i = 0; i < numGradients; i++) {
		gradientRecords.push_back(GRADRECORD(ds, shapeNum));
	}
	focalPoint = ds->readFIXED8();
}