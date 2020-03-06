#ifndef EX3_GRADIENT_H
#define EX3_GRADIENT_H

#include <vector>

#include "../io/DataStream.h"
#include "GRADRECORD.h"

namespace EX3 {
    class GRADIENT {
        public:
            int spreadMode;
            enum spreadModes {
                SPREAD_PAD_MODE = 0,
                SPREAD_REFLECT_MODE = 1,
                SPREAD_REPEAT_MODE = 2,
                SPREAD_RESERVED = 3
            };

            int interpolationMode;
            enum interpolationModes {
                INTERPOLATION_RGB_MODE = 0,
                INTERPOLATION_LINEAR_RGB_MODE = 1,
                INTERPOLATION_RESERVED1 = 2,
                INTERPOLATION_RESERVED2 = 3
            };

            std::vector<EX3::GRADRECORD> gradientRecords;

            GRADIENT();
            GRADIENT(EX3::DataStream* ds, int shapeNum);

            virtual void readData(EX3::DataStream* ds, int shapeNum);
        };
}

#endif //EX3_GRADIENT_H