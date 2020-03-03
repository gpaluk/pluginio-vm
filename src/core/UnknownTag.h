#ifndef EX3_UNKNOWNTAG_H
#define EX3_UNKNOWNTAG_H

#include "Tag.h"

using namespace std;

namespace EX3
{
    class UnknownTag : public EX3::Tag {
        public:
            UnknownTag(uint16_t tagId);

            void readData(EX3::DataStream* ds);

            string getName();
    };
} // namespace EX3

#endif //EX3_UNKNOWNTAG_H