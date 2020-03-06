#ifndef EX3_STYLECHANGERECORD_H
#define EX3_STYLECHANGERECORD_H

#include "SHAPERECORD.h"
#include "FILLSTYLEARRAY.h"
#include "LINESTYLEARRAY.h"

namespace EX3 {
    class StyleChangeRecord : public EX3::SHAPERECORD {
        public:
            static const bool typeFlag = false;
            bool stateNewStyles;
            bool stateLineStyle;
            bool stateFillStyle1;
            bool stateFillStyle0;
            bool stateMoveTo;
            int moveBits;
            int moveDeltaX;
            int moveDeltaY;
            int fillStyle0;
            int fillStyle1;
            int lineStyle;
            EX3::FILLSTYLEARRAY fillStyles;
            EX3::LINESTYLEARRAY lineStyles;
            int numFillBits;
            int numLineBits;

            StyleChangeRecord(EX3::DataStream* ds, int fillBits, int lineBits, int shapeNum);

            void readData(EX3::DataStream* ds, int fillBits, int lineBits, int shapeNum);
            int changeX(int x);
            int changeY(int y);
    };
}

#endif //EX3_STYLECHANGERECORD_H