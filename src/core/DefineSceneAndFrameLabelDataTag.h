#ifndef EX3_DEFINESCENEANDFRAMELABELDATATAG_H
#define EX3_DEFINESCENEANDFRAMELABELDATATAG_H

#include <string>
#include <vector>

#include "Tag.h"

using namespace std;

namespace EX3 {
    class DefineSceneAndFrameLabelDataTag : public EX3::Tag {
        public:
            static const uint16_t ID = 86;

            vector<uint32_t> sceneOffsets;
            vector<string> sceneNames;

            vector<uint32_t> frameNums;
            vector<string> frameNames;

            DefineSceneAndFrameLabelDataTag(EX3::DataStream* ds);

            void readData(EX3::DataStream* ds);
    };
}

#endif //EX3_DEFINESCENEANDFRAMELABELDATATAG_H