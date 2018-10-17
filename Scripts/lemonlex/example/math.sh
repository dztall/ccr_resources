rm -rf example/math
binary/lemon -d./example/math example/math.y -m -s &&
gcc example/math/math.c -o example/math/m &&
example/math/m &&
ls example/math &&
cat example/math/math.h &&
exit 0
