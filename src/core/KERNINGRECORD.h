#ifndef EX3_KERNINGRECORD_H
#define EX3_KERNINGRECORD_H

#include <stdint.h>

#include "SwfBaseTypes.h"
#include "../io/DataStream.h"

namespace EX3 {
    class KERNINGRECORD {
        public:
            uint16_t fontKerningCode1;
            uint16_t fontKerningCode2;
            int16_t fontKerningAdjustment;

            KERNINGRECORD(EX3::DataStream* ds, bool fontFlagsWideCodes);

            void readData(EX3::DataStream* ds, bool fontFlagsWideCodes);
    };
}

#endif //EX3_KERNINGRECORD_H