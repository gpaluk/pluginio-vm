#ifndef EX3_GRADRECORD_H
#define EX3_GRADRECORD_H

#include "DataStream.h"
#include "RGB.h"

namespace EX3 {
    class GRADRECORD {
        public:
            int ratio;
            bool inShape3;
            EX3::RGB color;

            GRADRECORD();
            GRADRECORD(EX3::DataStream* ds, int shapeNum);

            void readData(EX3::DataStream* ds, int shapeNum);
    };
}

#endif //EX3_GRADRECORD_H