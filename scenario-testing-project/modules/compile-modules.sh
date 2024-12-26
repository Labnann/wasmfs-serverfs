cd "$(dirname "$0")"
$CC -shared -fPIC -o hello0.so hello0.c
$CC -shared -fPIC -o hello1.so hello1.c
$CC -shared -fPIC -o hello2.so hello2.c
$CC -shared -fPIC -o hello3.so hello3.c
$CC -shared -fPIC -o hello4.so hello4.c

