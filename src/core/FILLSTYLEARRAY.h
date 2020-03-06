#ifndef EX3_FILLSTYLEARRAY_H
#define EX3_FILLSTYLEARRAY_H

#include <vector>

#include "FILLSTYLE.h"

namespace EX3 {
    class FILLSTYLEARRAY {
        public:
            std::vector<EX3::FILLSTYLE> fillStyles;

            FILLSTYLEARRAY();
            FILLSTYLEARRAY(EX3::DataStream* ds, int shapeNum);

            void readData(EX3::DataStream* ds, int shapeNum);
    };
}

#endif //EX3_FILLSTYLEARRAY_H