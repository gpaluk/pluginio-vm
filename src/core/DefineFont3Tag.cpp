#include <iostream>

#include "DefineFont3Tag.h"

EX3::DefineFont3Tag::DefineFont3Tag(EX3::DataStream *ds) : EX3::Tag(ID, "DefineFont3"){
	readData(ds);
}

void EX3::DefineFont3Tag::readData(EX3::DataStream *ds) {
	fontId = ds->readUInt16();
	fontFlagsHasLayout = ds->readUBits(1) == 1;
	fontFlagsShiftJIS = ds->readUBits(1) == 1;
	fontFlagsSmallText = ds->readUBits(1) == 1;
	fontFlagsANSI = ds->readUBits(1) == 1;
	fontFlagsWideOffsets = ds->readUBits(1) == 1;
	fontFlagsWideCodes = ds->readUBits(1) == 1;
	fontFlagsItalic = ds->readUBits(1) == 1;
	fontFlagsBold = ds->readUBits(1) == 1;
	languageCode = ds->readLANGCODE();
	uint8_t fontNameLen = ds->readUInt8();
	fontName = ds->readString(fontNameLen);

	uint16_t numGlyphs = ds->readUInt16();
	uint32_t offsetTable [numGlyphs];
	long index = ds->getPosition();
	for (int i = 0; i < numGlyphs; i++) {
		if (fontFlagsWideOffsets)
			offsetTable[i] = ds->readUInt32();
		else
			offsetTable[i] = ds->readUInt16();
	}

	if (numGlyphs > 0) {
		if (fontFlagsWideOffsets)
			ds->readUInt32(); //codeTableOffset
		else
			ds->readUInt16(); //codeTableOffset
	}

	for (int i = 0; i < numGlyphs; i++) {
		ds->seek(index + offsetTable[i]);
		glyphShapeTable.push_back(EX3::SHAPE(ds, 1));
	}

	for (int i = 0; i < numGlyphs; i++) {
		if (fontFlagsWideCodes)
			codeTable.push_back(ds->readUInt16());
		else
			codeTable.push_back(ds->readUInt8());
	}

	if (fontFlagsHasLayout) {
		fontAscent = ds->readUInt16();
		fontDescent = ds->readUInt16();
		fontLeading = ds->readInt16();

		for (int i = 0; i < numGlyphs; i++) {
			fontAdvanceTable.push_back(ds->readInt16());
		}
		for (int i = 0; i < numGlyphs; i++) {
			fontBoundsTable.push_back(EX3::RECT(ds));
		}
		uint16_t kerningCount = ds->readUInt16();
		for (int i = 0; i < kerningCount; i++) {
			fontKerningTable.push_back(EX3::KERNINGRECORD(ds, fontFlagsWideCodes));
		}
	}
}