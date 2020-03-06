#ifndef EX3_DEFINEFONT3TAG_H
#define EX3_DEFINEFONT3TAG_H

#include <vector>

#include "Tag.h"
#include "LANGCODE.h"
#include "SHAPE.h"
#include "RECT.h"
#include "KERNINGRECORD.h"

namespace EX3 {
    class DefineFont3Tag : public EX3::Tag {
        public:
            static const uint16_t ID = 75;

            uint16_t fontId;
            bool fontFlagsHasLayout;
            bool fontFlagsShiftJIS;
            bool fontFlagsSmallText;
            bool fontFlagsANSI;
            bool fontFlagsWideOffsets;
            bool fontFlagsWideCodes;
            bool fontFlagsItalic;
            bool fontFlagsBold;
            EX3::LANGCODE languageCode;
            string fontName;
            vector<EX3::SHAPE> glyphShapeTable;
            vector<uint16_t> codeTable;
            uint16_t fontAscent;
            uint16_t fontDescent;
            int16_t fontLeading;
            vector<int16_t> fontAdvanceTable;
            vector<EX3::RECT> fontBoundsTable;
            vector<EX3::KERNINGRECORD> fontKerningTable;

            DefineFont3Tag(EX3::DataStream* ds);

            void readData(EX3::DataStream* ds);
    };
}

#endif //EX3_DEFINEFONT3TAG_H