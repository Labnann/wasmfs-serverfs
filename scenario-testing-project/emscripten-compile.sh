export CC=emcc
./modules/emscripten-compile-modules.sh
$CC main.c -o main.html -sMAIN_MODULE=1 -s EXPORTED_FUNCTIONS="_main"
