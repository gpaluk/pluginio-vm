#include "ABC.h"

EX3::ABC::ABC() {
	readData();
}

void EX3::ABC::readData() {
	// TODO: read u16 major_version
	// TODO: read u16 minor_version
	constant_pool = EX3::ConstantPoolInfo();

	// TODO: read u30 method_count
	// TODO: read u30 method_info

	// TODO: read u30 metadata_count
	// TODO: read u30 metadata_info

	// TODO: read u30 class_count
	// TODO: read u30 instance_info
	// TODO: read u30 class_info

	// TODO: read u30 script_count
	// TODO: read u30 script_info

	// TODO: read u30 method_body_count
	// TODO: read u30 method_body_info
}