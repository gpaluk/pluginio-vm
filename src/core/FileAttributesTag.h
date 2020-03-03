#ifndef EX3_FILEATTRIBUTESTAG_H
#define EX3_FILEATTRIBUTESTAG_H

#include "Tag.h"

namespace EX3
{
    class FileAttributesTag : public EX3::Tag {
        public:
            static const uint16_t ID = 69;

            bool reserved1;
            bool useDirectBlit;
            bool useGPU;
            bool hasMetadata;
            bool actionScript3;
            bool noCrossDomainCache;
            bool reserved2;
            bool useNetwork;
            int reserved3;

            FileAttributesTag(EX3::DataStream* ds);
            void readData(EX3::DataStream* ds);
    };
}

#endif //EX3_FILEATTRIBUTESTAG_H