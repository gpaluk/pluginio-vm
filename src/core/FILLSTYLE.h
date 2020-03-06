#ifndef EX3_FILLSTYLE_H
#define EX3_FILLSTYLE_H

#include <stdint.h>

#include "RGB.h"
#include "MATRIX.h"
#include "GRADIENT.h"

namespace EX3 {
    class FILLSTYLE {
        public:
            uint8_t fillStyleType;
            enum fillStyleTypes {
                SOLID = 0x0,
                LINEAR_GRADIENT = 0x10,
                RADIAL_GRADIENT = 0x12,
                FOCAL_RADIAL_GRADIENT = 0x13,
                REPEATING_BITMAP = 0x40,
                CLIPPED_BITMAP = 0x41,
                NON_SMOOTHED_REPEATING_BITMAP = 0x42,
                NON_SMOOTHED_CLIPPED_BITMAP = 0x43
            };
            bool inShape3;
            EX3::RGB color;
            EX3::MATRIX gradientMatrix;
            EX3::GRADIENT gradient;
            int bitmapId;
            EX3::MATRIX bitmapMatrix;

            FILLSTYLE();
            FILLSTYLE(EX3::DataStream* ds, int shapeNum);

            void readData(EX3::DataStream* ds, int shapeNum);
    };
}

#endif //EX3_FILLSTYLE_H