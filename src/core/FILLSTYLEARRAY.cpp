#include "FILLSTYLEARRAY.h"

EX3::FILLSTYLEARRAY::FILLSTYLEARRAY() {
}

EX3::FILLSTYLEARRAY::FILLSTYLEARRAY(EX3::DataStream *ds, int shapeNum) {
	readData(ds, shapeNum);
}

void EX3::FILLSTYLEARRAY::readData(EX3::DataStream *ds, int shapeNum) {
	uint16_t fillStyleCount = ds->readUInt8();
	if (((shapeNum == 2) || (shapeNum == 3) || (shapeNum == 4/*?*/)) && (fillStyleCount == 0xFF)) {
		fillStyleCount = ds->readUInt16();
	}

	for (int i = 0; i < fillStyleCount; i++) {
		fillStyles.push_back(EX3::FILLSTYLE(ds, shapeNum));
	}
}