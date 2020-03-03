#ifndef EX3_TAGSTUB_H
#define EX3_TAGSTUB_H

#include "Tag.h"

using namespace std;

namespace EX3
{
    class TagStub : public EX3::Tag
    {
        private:
            EX3::DataStream *tagDataStream;
        public:
            TagStub(uint16_t tagId, string tagName, EX3::DataStream* tagDataStream);
	        ~TagStub();

	        void readData(EX3::DataStream* ds);
	        EX3::DataStream* getDataStream();
    };
} // namespace EX3

#endif //EX3_TAGSTUB_H