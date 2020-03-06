#include "KERNINGRECORD.h"

EX3::KERNINGRECORD::KERNINGRECORD(EX3::DataStream *ds, bool fontFlagsWideCodes) {
	readData(ds, fontFlagsWideCodes);
}

void EX3::KERNINGRECORD::readData(EX3::DataStream *ds, bool fontFlagsWideCodes) {
	if (fontFlagsWideCodes) {
		fontKerningCode1 = ds->readUInt16();
		fontKerningCode2 = ds->readUInt16();
	} else {
		fontKerningCode1 = ds->readUInt8();
		fontKerningCode2 = ds->readUInt8();
	}
	fontKerningAdjustment = ds->readInt16();
}