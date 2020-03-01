#ifndef EX3_TAGSTUB_H
#define EX3_TAGSTUB_H

#include "Tag.h"

namespace EX3
{
    class TagStub : public Tag
    {
        private:
            DataStream *tagDataStream;
        public:
            TagStub(uint16_t tagId, string tagName, DataStream* tagDataStream);
	        ~TagStub();

	        void readData(DataStream* ds);
	        DataStream* getDataStream();
    };
} // namespace EX3


#endif //EX3_TAGSTUB_H