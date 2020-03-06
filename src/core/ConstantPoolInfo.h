#ifndef EX3_CONSTANTPOOLINFO_H
#define EX3_CONSTANTPOOLINFO_H

#include <vector>
#include <stdint.h>
#include <string>

#include "NamespaceInfo.h"
#include "NamespaceSetInfo.h"
#include "MultinameInfo.h"

using namespace std;

namespace EX3 {
    class ConstantPoolInfo {
        public:
            vector<int32_t> constant_int;
            vector<uint32_t> constant_uint;
            vector<double> constant_double;
            vector<string> constant_string;
            vector<NamespaceInfo> constant_namespace;
            vector<NamespaceSetInfo> constant_ns_set;
            vector<MultinameInfo> constant_multiname;

            ConstantPoolInfo();

            void readData();
    };
}

#endif //EX3_CONSTANTPOOLINFO_H