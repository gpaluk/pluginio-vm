EMCC := em++
EMFLAGS := -std=c++11 --preload-file data/test.swf -Isrc/core -Isrc/io
PORTS := -s USE_ZLIB=1
SRC_DIR := ./src
SRC_FILES := $(SRC_DIR)/main.cpp \
			$(wildcard $(SRC_DIR)/core/*.cpp) \
			$(wildcard $(SRC_DIR)/io/*.cpp)

build: $(SRC_FILES)
	$(EMCC) $(EMFLAGS) $(SRC_FILES) $(PORTS) -o bin/vm.html

test:
	python -m SimpleHTTPServer 8080