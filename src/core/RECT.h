#ifndef EX3_RECT_H
#define EX3_RECT_H

#include <stdint.h>

#include "SwfBaseTypes.h"
#include "../io/DataStream.h"

namespace EX3
{
    class RECT
    {
        public:
            uint64_t nBits;
            int64_t Xmin;
            int64_t Xmax;
            int64_t Ymin;
            int64_t Ymax;

            RECT();
            RECT(int64_t Xmin, int64_t Xmax, int64_t Ymin, int64_t Ymax);
            RECT(EX3::RECT* r);
            RECT(EX3::DataStream* ds);

	        void readData(EX3::DataStream* ds);
    };
}

#endif //EX3_RECT_H