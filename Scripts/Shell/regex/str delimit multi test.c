#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *multi_tok(char *input, char * *string, char *delimiter) {
    if (input != NULL)
        *string = input;

    if (*string == NULL)
        return *string;

    char *end = strstr(*string, delimiter);
    if (end == NULL) {
        char *temp = *string;
        *string = NULL;
        return temp;
    }

    char *temp = *string;

    *end = '\0';
    *string = end + strlen(delimiter);
    return temp;
}

#define COMMAND         " ; "
#define PIPE            " | "
#define BACKGROUND      " & "
#define IF_RETURN_TRUE  " && "
#define IF_RETURN_FALSE " || "

int has_COMMAND			= 0;
int has_PIPE			= 0;
int has_BACKGROUND		= 0;
int has_IF_RETURN_TRUE	= 0;
int has_IF_RETURN_FALSE = 0;

int parseA(char * i, char * delim) {
	int c = 0;
	char * input = strdup(i);
	printf("\ninput: \"%s\"\n", input);
	printf("to split by: \"%s\"\n", delim);
	char * a = NULL;

    char *token = multi_tok(input, &a, delim);

    while (token != NULL) {
        printf("token: %s\n", token);
        if (strcmp(delim, IF_RETURN_TRUE) == 0) parseA(token, IF_RETURN_FALSE); // look for || if any
        token = multi_tok(NULL, &a, delim);
        c++;
    }
    return c;
}

void parseB(char * input) {
	if (has_PIPE || has_BACKGROUND || has_IF_RETURN_TRUE || has_IF_RETURN_FALSE) {
		puts("");
		puts("Started");
		if (has_PIPE) parseA(input, PIPE);
    	if (has_BACKGROUND) parseA(input, BACKGROUND);
    	
    	/*
    	
    	order of processing according to bash:
    	
    	true && true || false && true
    	equivilant to
    	( ( ( ( true ) && true ) || false ) && true )
    	
    	how would we correctly parse without producing duplicate information
    	
    	*/
    	
    	if (has_IF_RETURN_TRUE) {
    		char * sub_position = strstr(input, IF_RETURN_TRUE);
    		while (sub_position != NULL) {
    			printf("sub_position = %s\n", sub_position);
    			sub_position = strstr(sub_position+1, IF_RETURN_TRUE);
    			sleep(1);
    		}
    		parseA(input, IF_RETURN_TRUE);
    	}
    	if (has_IF_RETURN_FALSE) {
    		parseA(input, IF_RETURN_FALSE);
    	}
    	
    	
    	puts("");
    	puts("Ended");
    	puts("");
    }
    has_BACKGROUND 		= 0;
    has_COMMAND 		= 0;
    has_PIPE 			= 0;
    has_IF_RETURN_TRUE  = 0;
    has_IF_RETURN_FALSE = 0;
}

int position;

void parse(char * i, char * delim) {
	position = 0;
	char * token_buffer = malloc(strlen(i));
	char * buffer = malloc( strlen(i) );
	char * input = strdup(i);
	printf("\noriginal: \"%s\"\n", input);
	printf("to split by: \"%s\"\n", delim);
	char * a = NULL;

    char *token = multi_tok(input, &a, delim);

    while (token != NULL) {
    	if(strcmp(token, ";") == 0) {
    		position++;
        	printf("position: %d: ", position);
    		has_COMMAND = 1;
    		printf("token: %s  (command)\n", token);
    		parseB(buffer);
    		memset(buffer, 0, strlen(buffer));
    	}
    	else if(strcmp(token, "|") == 0) {
    		position++;
        	printf("position: %d: ", position);
    		has_PIPE = 1;
    		strcat(buffer, token);
        	strcat(buffer, " ");
    		printf("token: %s  (pipe)\n", token);
    	}
    	else if(strcmp(token, "&") == 0) {
    		position++;
        	printf("position: %d: ", position);
    		has_BACKGROUND = 1;
    		printf("token: %s  (background)\n", token);
    		parseB(buffer);
    		memset(buffer, 0, strlen(buffer));
    	}
    	else if(strcmp(token, "&&") == 0) {
    		position++;
        	printf("position: %d: ", position);
    		has_IF_RETURN_TRUE = 1;
    		strcat(buffer, token);
        	strcat(buffer, " ");
    		printf("token: %s (return if true)\n", token);
    	}
    	else if(strcmp(token, "||") == 0) {
    		position++;
        	printf("position: %d: ", position);
    		has_IF_RETURN_FALSE = 1;
    		strcat(buffer, token);
        	strcat(buffer, " ");
    		printf("token: %s (return if false)\n", token);
    	}
        else {
        	position++;
        	printf("position: %d: ", position);
        	printf("token: %s\n", token);
        	strcat(buffer, token);
        	strcat(buffer, " ");
        }
        token = multi_tok(NULL, &a, delim);
    }
    parseB(buffer);
    printf("buffer: %s\n", buffer);
    memset(buffer, 0, strlen(buffer));
    free(buffer);
}

int main() {
    char input [] = "this|is;a big&true&&true||false&&true;to split up";
    parse(input, " ");
    
}
