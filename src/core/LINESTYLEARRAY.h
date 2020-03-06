#ifndef EX3_LINESTYLEARRAY_H
#define EX3_LINESTYLEARRAY_H

#include <vector>

#include "../io/DataStream.h"
#include "LINESTYLE.h"

namespace EX3 {
    class LINESTYLEARRAY {
        public:
            std::vector<EX3::LINESTYLE> lineStyles;

            LINESTYLEARRAY();
            LINESTYLEARRAY(EX3::DataStream* ds, int shapeNum);

            void readData(EX3::DataStream* ds, int shapeNum);
    };
}

#endif //EX3_LINESTYLEARRAY_H