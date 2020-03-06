#include "LINESTYLEARRAY.h"
#include "LINESTYLE2.h"

EX3::LINESTYLEARRAY::LINESTYLEARRAY() {

}

EX3::LINESTYLEARRAY::LINESTYLEARRAY(EX3::DataStream *ds, int shapeNum) {
	readData(ds, shapeNum);
}

void EX3::LINESTYLEARRAY::readData(EX3::DataStream *ds, int shapeNum) {
	uint16_t lineStyleCount = ds->readUInt8();
	if (lineStyleCount == 0xFF) {
		lineStyleCount = ds->readUInt16();
	}
	if ((shapeNum == 1 || shapeNum == 2 || shapeNum == 3)) {
		for (int i = 0; i < lineStyleCount; i++) {
			lineStyles.push_back(EX3::LINESTYLE(ds, shapeNum));
		}
	} else if (shapeNum == 4) {
		for (int i = 0; i < lineStyleCount; i++) {
			lineStyles.push_back(EX3::LINESTYLE2(ds, shapeNum));
		}
	}
}