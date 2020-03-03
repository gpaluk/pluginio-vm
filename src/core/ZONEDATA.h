#ifndef EX3_ZONEDATA_H
#define EX3_ZONEDATA_H

#include "../io/DataStream.h"

namespace EX3
{
    class ZONEDATA {
        public:
            float alignmentCoordinate;
            float range;

            ZONEDATA(EX3::DataStream* ds);

            void readData(EX3::DataStream* ds);

            string toString();
    };
}

#endif //EX3_ZONEDATA_H