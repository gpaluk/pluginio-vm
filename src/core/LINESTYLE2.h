#ifndef EX3_LINESTYLE2_H
#define EX3_LINESTYLE2_H

#include "LINESTYLE.h"
#include "FILLSTYLE.h"

namespace EX3 {
    class LINESTYLE2 : public EX3::LINESTYLE {
        public:
            unsigned startCapStyle;
            unsigned joinStyle;
            enum joinStyles {
                ROUND_JOIN = 0,
                BEVEL_JOIN = 1,
                MITER_JOIN = 2
            };
            bool hasFillFlag;
            bool noHScaleFlag;
            bool noVScaleFlag;
            bool pixelHintingFlag;
            unsigned reserved;
            bool noClose;
            unsigned endCapStyle;
            enum endCapStyles {
                ROUND_CAP = 0,
                NO_CAP = 1,
                SQUARE_CAP = 2
            };
            uint16_t miterLimitFactor;
            EX3::FILLSTYLE fillType;

            LINESTYLE2();
            LINESTYLE2(EX3::DataStream* ds, int shapeNum);

            void readData(EX3::DataStream* ds, int shapeNum);
    };
}

#endif //EX3_LINESTYLE2_H