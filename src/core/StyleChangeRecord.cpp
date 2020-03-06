#include "StyleChangeRecord.h"

EX3::StyleChangeRecord::StyleChangeRecord(EX3::DataStream *ds, int fillBits, int lineBits, int shapeNum) {
	readData(ds, fillBits, lineBits, shapeNum);
}

void EX3::StyleChangeRecord::readData(EX3::DataStream *ds, int fillBits, int lineBits, int shapeNum) {
	stateNewStyles = ds->readUBits(1) == 1;
	stateLineStyle = ds->readUBits(1) == 1;
	stateFillStyle1 = ds->readUBits(1) == 1;
	stateFillStyle0 = ds->readUBits(1) == 1;
	stateMoveTo = ds->readUBits(1) == 1;
	if ((!stateNewStyles) && (!stateLineStyle) && (!stateFillStyle1) && (!stateFillStyle0) && (!stateMoveTo))
		return;
	if (stateMoveTo) {
		moveBits = (int) ds->readUBits(5);
		moveDeltaX = (int) ds->readBits(moveBits);
		moveDeltaY = (int) ds->readBits(moveBits);
	}
	if (stateFillStyle0) {
		fillStyle0 = (int) ds->readUBits(fillBits);
	}
	if (stateFillStyle1) {
		fillStyle1 = (int) ds->readUBits(fillBits);
	}
	if (stateLineStyle) {
		lineStyle = (int) ds->readUBits(lineBits);
	}
	if (stateNewStyles) {
		fillStyles = EX3::FILLSTYLEARRAY(ds, shapeNum);
		lineStyles = EX3::LINESTYLEARRAY(ds, shapeNum);

		numFillBits = (int) ds->readUBits(4);
		numLineBits = (int) ds->readUBits(4);
	}
}

int EX3::StyleChangeRecord::changeX(int x) {
	if (stateMoveTo) {
		return moveDeltaX;
	}
	return x;
}

int EX3::StyleChangeRecord::changeY(int y) {
	if (stateMoveTo) {
		return moveDeltaY;
	}
	return y;
}