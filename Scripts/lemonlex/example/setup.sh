gcc defgen.c -o binary/defgen &&
binary/defgen &&
gcc lemon.c -o binary/lemon -DLEMONEX_DBG=2 -g3 &&
exit 0
