#ifndef EX3_ZONERECORD_H
#define EX3_ZONERECORD_H

#include <vector>
#include <stdint.h>

#include "../io/DataStream.h"
#include "ZONEDATA.h"

using namespace std;

namespace EX3
{
    class ZONERECORD {
        public:
            vector<EX3::ZONEDATA> zonedata;
            bool reserved;
            bool zoneMaskX;
            bool zoneMaskY;

            ZONERECORD(EX3::DataStream* ds);

            void readData(EX3::DataStream* ds);
    };
}

#endif //EX3_ZONERECORD_H