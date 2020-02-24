#include "Tag.h"

EX3::Tag::Tag(uint16_t tagId, string tagName) {
	this->id = tagId;
	this->tagName = tagName;
}

uint16_t EX3::Tag::getId() {
	return id;
}

string EX3::Tag::getName() {
	return tagName;
}