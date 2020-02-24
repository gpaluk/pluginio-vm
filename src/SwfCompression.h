#ifndef EX3_SWFCOMPRESSION_H
#define EX3_SWFCOMPRESSION_H

namespace EX3
{
    enum SwfCompression {
        NONE = 'F',
        ZLIB = 'C',
        LZMA = 'Z'
    };
};

#endif //EX3_SWFCOMPRESSION_H