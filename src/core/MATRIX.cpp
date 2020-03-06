#include "MATRIX.h"

EX3::MATRIX::MATRIX() {

}

EX3::MATRIX::MATRIX(EX3::MATRIX *m) {
	if (!m) {
		return;
	}
	hasScale = m->hasScale;
	hasRotate = m->hasRotate;
	scaleX = m->scaleX;
	scaleY = m->scaleY;
	rotateSkew0 = m->rotateSkew0;
	rotateSkew1 = m->rotateSkew1;
	translateX = m->translateX;
	translateY = m->translateY;
}

EX3::MATRIX::MATRIX(EX3::DataStream *ds) {
	readData(ds);
}

void EX3::MATRIX::readData(DataStream *ds) {
	hasScale = ds->readUBits(1) == 1;
	if (hasScale) {
		int NScaleBits = (int) ds->readUBits(5);
		scaleX = (int) ds->readBits(NScaleBits);
		scaleY = (int) ds->readBits(NScaleBits);
		nScaleBits = NScaleBits;
	}
	hasRotate = ds->readUBits(1) == 1;
	if (hasRotate) {
		int NRotateBits = (int) ds->readUBits(5);
		rotateSkew0 = (int) ds->readBits(NRotateBits);
		rotateSkew1 = (int) ds->readBits(NRotateBits);
		nRotateBits = NRotateBits;
	}
	int NTranslateBits = (int) ds->readUBits(5);
	translateX = (int) ds->readBits(NTranslateBits);
	translateY = (int) ds->readBits(NTranslateBits);
	nTranslateBits = NTranslateBits;
	ds->alignByte();
}