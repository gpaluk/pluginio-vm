  
#ifndef EX3_NAMESPACESETINFO_H
#define EX3_NAMESPACESETINFO_H

#include <vector>
#include <stdint.h>

using namespace std;

namespace EX3 {
    class NamespaceSetInfo {
        public:
            vector<uint32_t> ns;

            NamespaceSetInfo();
            NamespaceSetInfo(vector<uint32_t> ns);

            void readData();
        };
}

#endif //EX3_NAMESPACESETINFO_H