#ifndef EX3_NAMESPACEINFO_H
#define EX3_NAMESPACEINFO_H

#include <stdint.h>

namespace EX3
{
    class NamespaceInfo {
        public:
            uint8_t kind;
            enum namespaceKinds {
                KIND_NAMESPACE = 0x08,
                KIND_PACKAGE = 0x16,
                KIND_PACKAGE_INTERNAL = 0x17,
                KIND_PROTECTED = 0x18,
                KIND_EXPLICIT = 0x19,
                KIND_STATIC_PROTECTED = 0x1A,
                KIND_PRIVATE = 0x05
            };
            uint32_t name;

            NamespaceInfo();
            NamespaceInfo(uint8_t kind, uint32_t name);

            void readData();
    };
}

#endif //EX3_NAMESPACEINFO_H