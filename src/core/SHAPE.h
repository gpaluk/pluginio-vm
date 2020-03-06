#ifndef EX3_SHAPE_H
#define EX3_SHAPE_H

#include <vector>
#include "SHAPERECORD.h"
#include "DataStream.h"

using namespace std;

namespace EX3 {
    class SHAPE {
        public:
            int numFillBits;
            int numLineBits;
            vector<EX3::SHAPERECORD*> shapeRecords;

            SHAPE(EX3::DataStream* ds, int shapeNum);

            void readData(EX3::DataStream* ds, int shapeNum);
    };
}

#endif //EX3_SHAPE_H