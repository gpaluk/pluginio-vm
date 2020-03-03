#include "RGB.h"

EX3::RGB::RGB() {

}

EX3::RGB::RGB(uint8_t red, uint8_t green, uint8_t blue) {
	this->red = red;
	this->green = green;
	this->blue = blue;
}

EX3::RGB::RGB(EX3::RGB *r) {
	red = r->red;
	green = r->green;
	blue = r->blue;
}

EX3::RGB::RGB(EX3::DataStream *ds) {
	readData(ds);
}

void EX3::RGB::readData(EX3::DataStream *ds) {
	red = ds->readUInt8();
	green = ds->readUInt8();
	blue = ds->readUInt8();
}