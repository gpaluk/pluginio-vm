#ifndef EX3_SYMBOLCLASSTAG_H
#define EX3_SYMBOLCLASSTAG_H

#include "Tag.h"

namespace EX3
{
    class SymbolClassTag : public EX3::Tag {
        public:
            static const uint16_t ID = 76;

            vector<uint16_t > tags;
            vector<string> names;

            SymbolClassTag(EX3::DataStream* ds);

            void readData(EX3::DataStream* ds);
    };
}

#endif //EX3_SYMBOLCLASSTAG_H