#ifndef EX3_DOABCDEFINETAG_H
#define EX3_DOABCDEFINETAG_H

#include "Tag.h"
#include "ABC.h"

namespace EX3
{
    class DoABCDefineTag : public EX3::Tag {
        public:
            static const uint16_t ID = 82;

            uint32_t flags;
            string name;

            DoABCDefineTag(EX3::DataStream* ds);

            void readData(EX3::DataStream* ds);

        private:
            ABC abcData;
        };
}

#endif //EX3_DOABCDEFINETAG_H