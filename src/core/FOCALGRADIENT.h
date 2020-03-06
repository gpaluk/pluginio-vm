#ifndef EX3_FOCALGRADIENT_H
#define EX3_FOCALGRADIENT_H

#include "GRADIENT.h"

namespace EX3 {
    class FOCALGRADIENT : public EX3::GRADIENT {
        public:
            float focalPoint;

            FOCALGRADIENT(EX3::DataStream* ds, int shapeNum);

            void readData(EX3::DataStream* ds, int shapeNum);
    };
}

#endif //EX3_FOCALGRADIENT_H