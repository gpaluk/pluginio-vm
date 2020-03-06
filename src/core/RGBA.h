#ifndef EX3_RGBA_H
#define EX3_RGBA_H

#include "RGB.h"

namespace EX3 {
    class RGBA : public EX3::RGB {
        public:
            int alpha;

            RGBA(EX3::DataStream* ds);
            RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
            RGBA(EX3::RGBA* r);

            void readData(EX3::DataStream* ds);
    };
}

#endif //EX3_RGBA_H