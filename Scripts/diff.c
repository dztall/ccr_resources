#include<stdio.h>
#include<string.h>
//a
#include <fcntl.h>
#include <stdlib.h>//
#include <unistd.h>

int main(int argc,char *argv[])
{
    FILE *file1,*file2;
    char * line1 = malloc(4096);
    char * line2 = malloc(4096);
    int line_count1=1,line_count2=1;
    int i=0,j=0,k=0,n=0,m=0,o=0;
    if (argc < 3) {
    	puts("usage: diff file1 file2");
    	return -1;
    }
    if (access(argv[1], F_OK)) {
    	perror(argv[1]);
    	return -1;
    }
    if (access(argv[2], F_OK)) {
    	perror(argv[2]);
    	return -1;
    }
    file1 = fopen(argv[1],"r");
    file2 = fopen(argv[2],"r");
    while (1) {
    	if(fscanf(file1,"%[^\n]\n",line1)!=EOF && fscanf(file2,"%[^\n]\n",line2)!=EOF) {
    		if(k == 1 && strcmp(line1,line2) != 0) {
    			k=0;
    			printf("lines %d to %d are the same\n", n, m-1);
    		}
    		if(strcmp(line1,line2) == 0) {
    			if(k == 0) {
    				n = line_count1;
    				k = 1;
    			}
    			//printf("Same for both files: line %d : %s\n", line_count1, line1);
    		}
    		else {
    			printf("%s: \tline %d: %s\n", argv[1], line_count1, line1);
    			printf("%s: \tline %d: %s\n", argv[2], line_count2, line2);
    		}
    	}
    	else break;
    	line_count1++;
        line_count2++;
    	m = line_count1;
    }
    line_count1++;
    line_count2++;
    m = line_count1;
    if(k == 1) {
    	k=0;
    	printf("lines %d to %d are the same\n", n, m);
    }
    free(line1);
    free(line2);
    fclose(file1);
    fclose(file2);
    return 0;
}








//
