
/*
#include "../Garbage_Collector/gc.h"
Garbage_Collector_Options = Garbage_Collector_Options_No_Recycle;
Garbage_Collector_Debug = Garbage_Collector_Debug_Normal;//Garbage_Collector_Debug_Free | Garbage_Collector_Debug_Realloc | Garbage_Collector_Debug_List;

*/
#include<stdio.h>
#include<string.h>
//a
#include <fcntl.h>
#include <stdlib.h>//
#include <unistd.h>
#include "builtins/getline.h"

int get_file(char *file, int line)
{
    FILE *file1;
    char * line1 = malloc(4096);
    int line_count1=1;
    size_t m=0;
    
    if (access(file, F_OK)) {
    	perror(file);
    	return -1;
    }
    file1 = fopen(file,"r");
    while (1) {
    	//if(fscanf(file1,"%[^\n]\n",line1)!=EOF) if (line_count1 >= line) break;
    	//if(getline(&line1,&m,file1)!=0) if (line_count1 >= line) break;
    	if(fgets(line1, 4096, file1)!=0) if (line_count1 >= line) break;
    	line_count1++;
    }
    printf("%s: %d: %s", file, line_count1, line1);
    free(line1);
    fclose(file1);
    return 0;
}

int main(void) {
	get_file("builtins/env.h", 191);
	//Garbage_Collector_Shutdown();
	return 0;
}




//
