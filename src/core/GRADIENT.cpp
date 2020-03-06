#include "GRADIENT.h"

EX3::GRADIENT::GRADIENT() {

}

EX3::GRADIENT::GRADIENT(EX3::DataStream *ds, int shapeNum) {
	readData(ds, shapeNum);
}

void EX3::GRADIENT::readData(EX3::DataStream *ds, int shapeNum) {
	spreadMode = (int) ds->readUBits(2);
	interpolationMode = (int) ds->readUBits(2);

	int numGradients = (int) ds->readUBits(4);
	for (int i = 0; i < numGradients; i++) {
		gradientRecords.push_back(EX3::GRADRECORD(ds, shapeNum));
	}
}