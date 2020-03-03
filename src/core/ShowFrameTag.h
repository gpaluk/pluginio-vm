#ifndef EX3_SHOWFRAMETAG_H
#define EX3_SHOWFRAMETAG_H

#include "Tag.h"

namespace EX3
{
    class ShowFrameTag : public EX3::Tag {
        public:
            static const uint16_t ID = 1;
            ShowFrameTag(EX3::DataStream* ds);
            void readData(EX3::DataStream* ds);
    };
}

#endif //EX3_SHOWFRAMETAG_H