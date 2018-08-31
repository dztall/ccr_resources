#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "execute.h"
#include "command.h"

int main()
{
	// ignore Ctrl-\ Ctrl-C Ctrl-Z signals
	//ignore_signal_for_shell();

	// set the prompt
	//set_prompt("swoorup % ");

	while (1)
	{
		char* linebuffer;
		size_t len;

		lexer_t lexerbuf;
		ASTreeNode* exectree;

		// keep getline in a loop in case interruption occurs
		int again = 1;
		while (again) {
			again = 0;
			//printf("%s", getprompt());
			linebuffer = NULL;
			len = 0;
			char input[4096];
			char charcurrent;
			// clear last input
			memset(input, 0, 4096);
			charcurrent = 0;
			while(charcurrent!='\n') {
				charcurrent = getchar();
				if (charcurrent != '\n') sprintf(input, "%s%c", input, charcurrent);
				len++;
			}
			printf("recieved %s\n", input);
			linebuffer = input;
		}

		/*// user pressed ctrl-D
		if (feof(stdin)) {
			exit(0);
			return 0;
		}
*/
		// lexically analyze and build a list of tokens
		lexer_build(linebuffer, len, &lexerbuf);

		// parse the tokens into an abstract syntax tree
		if (!lexerbuf.ntoks || parse(&lexerbuf, &exectree) != 0) {
			continue;
		}

		execute_syntax_tree(exectree);

		// free the structures
		ASTreeNodeDelete(exectree);
		lexer_destroy(&lexerbuf);
	}

	return 0;
}

