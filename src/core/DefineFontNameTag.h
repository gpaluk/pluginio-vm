#ifndef EX3_DEFINEFONTNAMETAG_H
#define EX3_DEFINEFONTNAMETAG_H

#include "Tag.h"

namespace EX3 {
    class DefineFontNameTag : public EX3::Tag {
        public:
            static const uint16_t ID = 88;

            uint16_t fontId;
            string fontName;
            string fontCopyright;

            DefineFontNameTag(EX3::DataStream* ds);

            void readData(EX3::DataStream* ds);
    };
}

#endif //EX3_DEFINEFONTNAMETAG_H