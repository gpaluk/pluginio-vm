em++ -std=c++11 -Wc++11-extensions --preload-file src/_test.swf -o bin/vm.html -I/src/ src/DataStream.cpp src/Swf.cpp src/SwfParser.cpp src/main.cpp
REM python -m SimpleHTTPServer 8080