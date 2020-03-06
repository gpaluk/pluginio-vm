#include "NamespaceInfo.h"

EX3::NamespaceInfo::NamespaceInfo() {
}

EX3::NamespaceInfo::NamespaceInfo(uint8_t kind, uint32_t name) {
	this->kind = kind;
	this->name = name;
}

void EX3::NamespaceInfo::readData() {
	//TODO: read kind
	//TODO: read name
}