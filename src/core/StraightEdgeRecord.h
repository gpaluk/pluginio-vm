#ifndef EX3_STRAIGHTEDGERECORD_H
#define EX3_STRAIGHTEDGERECORD_H

#include "SHAPERECORD.h"
#include "DataStream.h"

namespace EX3 {
    class StraightEdgeRecord : public EX3::SHAPERECORD {
        public:
            static const bool typeFlag = true;
            static const bool straightFlag = true;
            unsigned numBits;
            bool generalLineFlag;
            bool vertLineFlag;
            int deltaX;
            int deltaY;

            StraightEdgeRecord(EX3::DataStream* ds);

            void readData(EX3::DataStream* ds);
            int changeX(int x);
            int changeY(int y);
        };
}

#endif //EX3_STRAIGHTEDGERECORD_H