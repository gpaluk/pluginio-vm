#ifndef EX3_LINESTYLE_H
#define EX3_LINESTYLE_H

#include <stdint.h>

#include "RGB.h"

namespace EX3 {
    class LINESTYLE {
        public:
            uint16_t width;
            EX3::RGB color;

            LINESTYLE();
            LINESTYLE(EX3::DataStream* ds, int shapeNum);

            virtual void readData(EX3::DataStream* ds, int shapeNum);
    };
}

#endif //EX3_LINESTYLE_H