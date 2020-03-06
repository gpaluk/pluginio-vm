#include "GRADRECORD.h"
#include "RGBA.h"

EX3::GRADRECORD::GRADRECORD() {

}

EX3::GRADRECORD::GRADRECORD(EX3::DataStream *ds, int shapeNum) {
	readData(ds, shapeNum);
}

void EX3::GRADRECORD::readData(EX3::DataStream *ds, int shapeNum) {
	ratio = ds->readUInt8();
	if (shapeNum >= 3) {
		color = EX3::RGBA(ds);
	} else {
		color = EX3::RGB(ds);
	}
}