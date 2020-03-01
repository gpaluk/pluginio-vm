#include "RECT.h"

EX3::RECT::RECT() {
}

EX3::RECT::RECT(int64_t Xmin, int64_t Xmax, int64_t Ymin, int64_t Ymax) {
	this->Xmin = Xmin;
	this->Xmax = Xmax;
	this->Ymin = Ymin;
	this->Ymax = Ymax;
}

EX3::RECT::RECT(RECT *r) {
	Xmin = r->Xmin;
	Xmax = r->Xmax;
	Ymin = r->Ymin;
	Ymax = r->Ymax;
}

EX3::RECT::RECT(DataStream * ds) {
	readData(ds);
}

void EX3::RECT::readData(DataStream *ds) {
	nBits = ds->readUBits(5);
	Xmin = ds->readBits((unsigned) nBits);
	Xmax = ds->readBits((unsigned) nBits);
	Ymin = ds->readBits((unsigned) nBits);
	Ymax = ds->readBits((unsigned) nBits);
	ds->alignByte();
}