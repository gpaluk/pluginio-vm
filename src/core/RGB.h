#ifndef EX3_RGB_H
#define EX3_RGB_H

#include <stdint.h>
#include "../io/DataStream.h"

namespace EX3
{
    class RGB {
        public:
            uint8_t red;
            uint8_t green;
            uint8_t blue;

            RGB();
            RGB(uint8_t red, uint8_t green, uint8_t blue);
            RGB(EX3::RGB* r);
            RGB(EX3::DataStream* ds);

            virtual void readData(EX3::DataStream* ds);
    };
}


#endif //EX3_RGB_H