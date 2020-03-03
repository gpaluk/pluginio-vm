#include "FileAttributesTag.h"

EX3::FileAttributesTag::FileAttributesTag(EX3::DataStream *ds) : EX3::Tag(ID, "FileAttributes") {
	readData(ds);
}

void EX3::FileAttributesTag::readData(EX3::DataStream *ds) {
	reserved1 = ds->readUBits(1) == 1;
	useDirectBlit = ds->readUBits(1) != 0;
	useGPU = ds->readUBits(1) != 0;
	hasMetadata = ds->readUBits(1) != 0;
	actionScript3 = ds->readUBits(1) != 0;
	noCrossDomainCache = ds->readUBits(1) != 0;
	reserved2 = ds->readUBits(1) == 1;
	useNetwork = ds->readUBits(1) != 0;
	reserved3 = (int)ds->readUBits(24);
}