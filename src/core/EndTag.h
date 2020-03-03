#ifndef EX3_ENDTAG_H
#define EX3_ENDTAG_H

#include "Tag.h"

using namespace std;

namespace EX3
{
    class EndTag : public EX3::Tag {
        public:
            static const uint16_t ID = 0;

            EndTag(EX3::DataStream* ds);
            ~EndTag();

            void readData(EX3::DataStream* ds);
    };
}

#endif //EX3_ENDTAG_H