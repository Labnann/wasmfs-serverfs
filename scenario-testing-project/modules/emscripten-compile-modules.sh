cd "$(dirname "$0")"
$CC -s SIDE_MODULE=1 -fPIC -o hello0.so hello0.c
$CC -s SIDE_MODULE=1 -fPIC -o hello1.so hello1.c
$CC -s SIDE_MODULE=1 -fPIC -o hello2.so hello2.c
$CC -s SIDE_MODULE=1 -fPIC -o hello3.so hello3.c
$CC -s SIDE_MODULE=1 -fPIC -o hello4.so hello4.c

