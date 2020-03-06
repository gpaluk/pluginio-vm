#include "CurvedEdgeRecord.h"

EX3::CurvedEdgeRecord::CurvedEdgeRecord(EX3::DataStream *ds) {
	readData(ds);
}

void EX3::CurvedEdgeRecord::readData(EX3::DataStream *ds) {
	numBits = (unsigned) ds->readUBits(4);
	controlDeltaX = (int) ds->readBits(numBits + 2);
	controlDeltaY = (int) ds->readBits(numBits + 2);
	anchorDeltaX = (int) ds->readBits(numBits + 2);
	anchorDeltaY = (int) ds->readBits(numBits + 2);
}

int EX3::CurvedEdgeRecord::changeX(int x) {
	return x + (controlDeltaX + anchorDeltaX);
}

int EX3::CurvedEdgeRecord::changeY(int y) {
	return y + (controlDeltaY + anchorDeltaY);
}