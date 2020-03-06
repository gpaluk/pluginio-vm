#include "StraightEdgeRecord.h"

EX3::StraightEdgeRecord::StraightEdgeRecord(EX3::DataStream *ds) {
	readData(ds);
}

void EX3::StraightEdgeRecord::readData(EX3::DataStream *ds) {
	numBits = (int) ds->readUBits(4);
	generalLineFlag = ds->readUBits(1) == 1;
	if (!generalLineFlag) {
		vertLineFlag = ds->readUBits(1) == 1;
	}
	if (generalLineFlag || (!vertLineFlag)) {
		deltaX = (int) ds->readBits(numBits + 2);
	}
	if (generalLineFlag || (vertLineFlag)) {
		deltaY = (int) ds->readBits(numBits + 2);
	}
}

int EX3::StraightEdgeRecord::changeX(int x) {
	if (generalLineFlag) {
		return x + deltaX;
	} else if (vertLineFlag) {
		return x;
	} else {
		return x + deltaX;
	}
}

int EX3::StraightEdgeRecord::changeY(int y) {
	if (generalLineFlag) {
		return y + deltaY;
	} else if (vertLineFlag) {
		return y + deltaY;
	} else {
		return y;
	}
}