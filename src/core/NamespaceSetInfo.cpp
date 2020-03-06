#include "NamespaceSetInfo.h"

EX3::NamespaceSetInfo::NamespaceSetInfo() {
}

EX3::NamespaceSetInfo::NamespaceSetInfo(vector<uint32_t> ns) {
	this->ns = ns;
}

void EX3::NamespaceSetInfo::readData() {
	// TODO: read u30 count
	// TODO: read ns
}