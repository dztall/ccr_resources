rm -rf example/parse
binary/lemon -dexample/parse ./example/parse.y -m &&
gcc example/parse/parse.c -o example/parse/parse &&
example/parse/parse &&
ls example/parse &&
cat example/parse/parse.h &&
exit 0
