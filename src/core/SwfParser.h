#ifndef EX3_SWFPARSER_H
#define EX3_SWFPARSER_H

#include <stdint.h>
#include <string>

#include "Swf.h"
#include "SwfCompression.h"
#include "RECT.h"
#include "Tag.h"
#include "RGB.h"
#include "TagStub.h"

using namespace std;

namespace EX3
{
    class SwfParser
    {
        private:
            EX3::Swf *swf;
            EX3::DataStream *ds;
            vector<uint8_t> data;
        public:
            SwfParser();
            SwfParser(Swf* swf);
            ~SwfParser();

            void readFromFile(const char* fileName);
            /*
            void readFromRawData(vector<uint8_t> data);
            void readFromRawData(uint8_t* data, size_t dataLength);
            static void decompress(vector<uint8_t> in, vector<uint8_t>& out);
            */
            EX3::Tag* readTag();
            static EX3::Tag* resolveTag(EX3::TagStub* t);
            void readTagList();
            
            bool isValidSwf();
    };
}

#endif