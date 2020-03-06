#ifndef EX3_CURVEDEDGERECORD_H
#define EX3_CURVEDEDGERECORD_H

#include "../io/DataStream.h"

namespace EX3 {
    class CurvedEdgeRecord : public EX3::SHAPERECORD {
        public:
            static const bool typeFlag = true;
            static const bool straightFlag = false;
            unsigned numBits;
            int controlDeltaX;
            int controlDeltaY;
            int anchorDeltaX;
            int anchorDeltaY;

            CurvedEdgeRecord(EX3::DataStream* ds);

            void readData(EX3::DataStream* ds);
            int changeX(int x);
            int changeY(int y);
        };
}

#endif //EX3_CURVEDEDGERECORD_H