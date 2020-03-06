#ifndef EX3_MATRIX_H
#define EX3_MATRIX_H

#include "DataStream.h"

namespace EX3 {
    class MATRIX {
        public:
            bool hasScale;
            int scaleX;
            int scaleY;
            bool hasRotate;
            int rotateSkew0;
            int rotateSkew1;
            int translateX;
            int translateY;
            int nTranslateBits;
            int nRotateBits;
            int nScaleBits;

            MATRIX();
            MATRIX(EX3::MATRIX* m);
            MATRIX(EX3::DataStream* ds);

            void readData(EX3::DataStream* ds);
    };
}

#endif //EX3_MATRIX_H