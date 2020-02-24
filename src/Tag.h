#ifndef EX3_TAG_H
#define EX3_TAG_H

#include <stdint.h>
#include <string>

#include "DataStream.h"

using namespace std;

namespace EX3
{
    class Tag
    {
        protected:
            uint16_t id;
	        string tagName;
        public:
            Tag(uint16_t tagId, string tagName);
            virtual ~Tag();

            virtual void readData(DataStream* ds) = 0;

            uint16_t getId();
            virtual string getName();
    };
};

#endif //EX3_TAG_H