emcc --preload-file src/_program.txt -o bin/vm.html -I/src/ src/vm.c src/ops.c
REM python -m SimpleHTTPServer 8080