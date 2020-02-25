em++ -std=c++11 -Wc++11-extensions --preload-file src/_test.swf -o bin/vm.html -I/src/ -I/thirdparty/zlib/ src/DataStream.cpp src/Swf.cpp src/SwfParser.cpp src/main.cpp
-I${EM_HOME}/thirdparty/zlib -L${EM_HOME}/thirdparty/zlib

REM python -m SimpleHTTPServer 8080