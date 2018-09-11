//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123

#include "Garbage_Collector/gc.h"
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

#include "Shell/builtins/getline.h"

// a cat like implimentation using getline

int
main(int argc, char *argv[])
{
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    if (argc != 2) {
        stream = stdin;
    }
    else {
    	if (access(argv[1],F_OK)) {
    		perror(argv[1]);
    		Garbage_Collector_Shutdown();
    		return -1;
    	}
    	stream = fopen(argv[1], "r");
    }
    if (stream == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    while ((nread = getline(&line, &len, stream)) != -1) {
        printf("Retrieved line of length %zu:\n", nread);
        printf("Retrieved line of size %zu:\n", len);
        fwrite(line, nread, 1, stdout);
        fwrite("\n", 1, 1, stdout);
    }

    free(line);
    if (fileno(stream) != fileno(stdin)) fclose(stream);
    Garbage_Collector_Shutdown();
    exit(EXIT_SUCCESS);
}

