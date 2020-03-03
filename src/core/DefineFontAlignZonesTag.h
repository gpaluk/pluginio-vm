#ifndef EX3_DEFINEFONTALIGNZONESTAG_H
#define EX3_DEFINEFONTALIGNZONESTAG_H

#include "Tag.h"
#include "ZONERECORD.h"

namespace EX3
{
    class DefineFontAlignZonesTag : public EX3::Tag {
        public:
            static const uint16_t ID = 73;

            uint16_t fontId;
            uint8_t CSMTableHint;
            bool reserved;
            vector<EX3::ZONERECORD> zoneTable;

            DefineFontAlignZonesTag(EX3::DataStream* ds);

            void readData(EX3::DataStream* ds);
    };
}

#endif //EX3_DEFINEFONTALIGNZONESTAG_H