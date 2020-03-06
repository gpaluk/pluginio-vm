#include "LINESTYLE.h"
#include "RGBA.h"

EX3::LINESTYLE::LINESTYLE() {

}

EX3::LINESTYLE::LINESTYLE(EX3::DataStream *ds, int shapeNum) {
	readData(ds, shapeNum);
}

void EX3::LINESTYLE::readData(EX3::DataStream *ds, int shapeNum) {
	width = ds->readUInt16();
	if ((shapeNum == 1) || (shapeNum == 2)) {
		color = EX3::RGB(ds);
	}
	if (shapeNum == 3) {
		color = EX3::RGBA(ds);
	}
}