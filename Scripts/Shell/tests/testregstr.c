#include "../builtins/regex_str.h"
#include "../builtins/printfmacro.h"

int main(void) {
	str_new(test);
	str_insert_string(test, "Hello World");
	str_insert_char(test, '!');
	str_insert_string(test, "\n");
	str_insert_int(test, 123456);
	str_insert_string(test, "\r\b\f\t''\"\"\\\n");
	str_insert_string(test, "'qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM foo\a\b\c\e\E\f\n\r\t\v\\\0255\xFF \1 \0255   あ  \343\201\202\'");
	str_insert_string(test, "\a\b\c\d\e\f\g\h\i\kj\k\l\m\n\o\p\q\r\s\t\v\w\y\z");
	str_info(test);
	str_free(test);
	/*
	char * s = "hello\nworld\n!";
	int * t;
	int count = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i-1] == '\n') count++;
        else {
            if (t == NULL) {
                t = malloc(sizeof(*t)*1);
                t[0] = 0;
            }
            if (i != 0) {
                int * k = realloc(t, sizeof(*t)*(i+1));
                if (k == NULL) break;
                t = k;
                t[i-1] = 0;
            }
			t[i-1] = count;
        }
	}
	
	ps(s);
	pc(s[6]);
	char * ss = "hello\\nworld\\n!";
	ps(ss);
	pc(ss[6+t[6]]);
	free(t);
	*/
	return -1;
}
