#ifndef EX3_SETBACKGROUNDCOLORTAG_H
#define EX3_SETBACKGROUNDCOLORTAG_H

#include "Tag.h"
#include "RGB.h"

namespace EX3
{
    class SetBackgroundColorTag : public EX3::Tag {
        public:
            static const uint16_t ID = 9;

            EX3::RGB backgroundColor;
            SetBackgroundColorTag(EX3::DataStream* ds);
            void readData(EX3::DataStream* ds);
    };
}

#endif //EX3_SETBACKGROUNDCOLORTAG_H