#include "SetBackgroundColorTag.h"

#include <iostream>

EX3::SetBackgroundColorTag::SetBackgroundColorTag(EX3::DataStream *ds) : EX3::Tag(ID, "SetBackgroundColor") {
	readData(ds);
}

void EX3::SetBackgroundColorTag::readData(EX3::DataStream *ds) {
	backgroundColor = EX3::RGB(ds);
	printf("Red: %u\n", backgroundColor.red);
	printf("Green: %u\n", backgroundColor.green);
	printf("Blue: %u\n", backgroundColor.blue);
}