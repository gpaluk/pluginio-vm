#include "LINESTYLE2.h"
#include "RGBA.h"

EX3::LINESTYLE2::LINESTYLE2() {

}

EX3::LINESTYLE2::LINESTYLE2(EX3::DataStream *ds, int shapeNum) {
	readData(ds, shapeNum);
}

void EX3::LINESTYLE2::readData(EX3::DataStream *ds, int shapeNum) {
	width = ds->readUInt16();
	startCapStyle = (unsigned) ds->readUBits(2);
	joinStyle = (unsigned) ds->readUBits(2);
	hasFillFlag = ds->readUBits(1) == 1;
	noHScaleFlag = ds->readUBits(1) == 1;
	noVScaleFlag = ds->readUBits(1) == 1;
	pixelHintingFlag = ds->readUBits(1) == 1;
	reserved = (unsigned) ds->readUBits(5);
	noClose = ds->readUBits(1) == 1;
	endCapStyle = (unsigned) ds->readUBits(2);
	if (joinStyle == joinStyles::MITER_JOIN) {
		miterLimitFactor = ds->readUInt16();
	}
	if (!hasFillFlag) {
		color = EX3::RGBA(ds);
	} else {
		fillType = EX3::FILLSTYLE(ds, shapeNum);
	}
}