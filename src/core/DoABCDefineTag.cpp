#include "DoABCDefineTag.h"

EX3::DoABCDefineTag::DoABCDefineTag(EX3::DataStream *ds) : EX3::Tag(ID, "DoABCDefine"){
	readData(ds);
}

void EX3::DoABCDefineTag::readData(EX3::DataStream *ds) {
	flags = ds->readUInt32();
	name = ds->readString();
	abcData = EX3::ABC();
}