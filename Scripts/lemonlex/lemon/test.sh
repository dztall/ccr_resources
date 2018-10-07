rm -rf p
cd ..
gcc defgen.c -o lemon/defgen &&
cd lemon &&
./defgen &&
gcc lexer_lemon.c -o lemon &&
./lemon ./p.y -Tlempar_lempar.c -dp &&
gcc -g3 p/p.c -o p/parse &&
gdb p/parse
ls -l p
