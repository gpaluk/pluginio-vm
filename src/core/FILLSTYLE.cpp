#include "FILLSTYLE.h"
#include "RGBA.h"
#include "FOCALGRADIENT.h"

EX3::FILLSTYLE::FILLSTYLE() {
}

EX3::FILLSTYLE::FILLSTYLE(EX3::DataStream *ds, int shapeNum) {
	readData(ds, shapeNum);
}

void EX3::FILLSTYLE::readData(EX3::DataStream *ds, int shapeNum) {
	fillStyleType = ds->readUInt8();
	if (fillStyleType == fillStyleTypes::SOLID) {
		if (shapeNum >= 3) {
			color = EX3::RGBA(ds);
		} else {
			color = EX3::RGB(ds);
		}
	}
	if ((fillStyleType ==fillStyleTypes::LINEAR_GRADIENT)
		|| (fillStyleType ==fillStyleTypes::RADIAL_GRADIENT)
		|| (fillStyleType ==fillStyleTypes::FOCAL_RADIAL_GRADIENT)) {
		gradientMatrix = EX3::MATRIX(ds);
	}
	if ((fillStyleType ==fillStyleTypes::LINEAR_GRADIENT)
		|| (fillStyleType ==fillStyleTypes::RADIAL_GRADIENT)) {
		gradient = EX3::GRADIENT(ds, shapeNum);
	}
	if (fillStyleType ==fillStyleTypes::FOCAL_RADIAL_GRADIENT) {
		gradient = EX3::FOCALGRADIENT(ds, shapeNum);
	}

	if ((fillStyleType ==fillStyleTypes::REPEATING_BITMAP)
		|| (fillStyleType ==fillStyleTypes::CLIPPED_BITMAP)
		|| (fillStyleType ==fillStyleTypes::NON_SMOOTHED_REPEATING_BITMAP)
		|| (fillStyleType ==fillStyleTypes::NON_SMOOTHED_CLIPPED_BITMAP)) {
		bitmapId = ds->readUInt16();
		bitmapMatrix = EX3::MATRIX(ds);
	}
}