#include "RGBA.h"

EX3::RGBA::RGBA(EX3::DataStream *ds) {
	readData(ds);
}

EX3::RGBA::RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) : EX3::RGB(red, green, blue)
{
	this->alpha = alpha;
}

EX3::RGBA::RGBA(EX3::RGBA *r) {
	red = r->red;
	green = r->green;
	blue = r->blue;
	alpha = r->alpha;
}

void EX3::RGBA::readData(EX3::DataStream *ds) {
	red = ds->readUInt8();
	green = ds->readUInt8();
	blue = ds->readUInt8();
	alpha = ds->readUInt8();
}