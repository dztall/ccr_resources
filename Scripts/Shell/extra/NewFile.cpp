#include <iostream>
struct line_ {
	const char * line;
	struct word_ {
		const char * word;
		const char * ch = word;
	} word[10];
} line[10];

int main(void) {
	line[0].line = "test line";
	line[0].word[0].word = "test";
	line[0].word[1].word = "line";
	std::cout << "line[0].line = " << line[0].line << ", line[0].word[0].word = " << line[0].word[0].word << ", line[0].word[0].ch[0] = " << line[0].word[0].ch[0] << std::endl;
	return 0;
}
