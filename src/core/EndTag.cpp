#include "EndTag.h"

EX3::EndTag::EndTag(EX3::DataStream *ds) : EX3::Tag(ID, "End") {
    readData(ds);
}

void EX3::EndTag::readData(EX3::DataStream *ds) {
}