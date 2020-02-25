EMCC := em++
EMFLAGS := -std=c++11 --preload-file src/_test.swf
PORTS := -s USE_ZLIB=1
SOURCES := src/DataStream.cpp src/Swf.cpp src/SwfParser.cpp src/main.cpp
SRC_DIR := ./src
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

build: $(SOURCES)
	$(EMCC) $(EMFLAGS) $(SOURCES) $(PORTS) -o bin/vm.html

test:
	python -m SimpleHTTPServer 8080