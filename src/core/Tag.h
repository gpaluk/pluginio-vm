#ifndef EX3_TAG_H
#define EX3_TAG_H

#include <stdint.h>
#include <string>

#include "../io/DataStream.h"

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
            //virtual ~Tag();

            virtual void readData(EX3::DataStream* ds) = 0;

            virtual uint16_t getId(){
                return id;
            };
            
            virtual string getName(){
                return tagName;
            };
    };
}

#endif //EX3_TAG_H