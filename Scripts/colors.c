//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123

#include "Garbage_Collector/gc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RESET		0
#define BRIGHT 		1
#define DIM			2
#define UNDERLINE 	3
#define BLINK		4
#define REVERSE		7
#define HIDDEN		8

#define BLACK 		0
#define RED			1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

char *attrs[] = {"NORMAL", "BRIGHT", "DIM", "UNDERLINE", "BLINK",
		 "REVERSE", "HIDDEN"};
char *colors[] = {"BLACK", "RED", "GREEN", "YELLOW", "BLUE", "MAGENTA",
		 "CYAN", "WHITE"};
void textcolor2(int attr, int fg, int bg);
int print_menu(char *array[], int n_options, char *title);
int menu()
{	int attr, fg, bg;
	int attr_size, colors_size;
	
	attr_size = ARRAY_SIZE(attrs);
	colors_size = ARRAY_SIZE(colors);
	while(1)
	{	printf("\n");
		// no error checking is done here
		attr = print_menu(attrs, attr_size, "Choose the attr you want, type -1 to exit:");
		if (attr == -1) break;
		fg = print_menu(colors, colors_size, "Choose the foreground you want, type -1 to exit:");
		if (fg == -1) break;
		bg = print_menu(colors, colors_size, "Choose the background you want, type -1 to exit:");
		if (bg == -1) break;
		printf("\n");
		textcolor2(attr, fg, bg);	
		printf("This is what you get if you use the combination %s attribute %s foreground and %s background", attrs[attr], colors[fg], colors[bg]);
		textcolor2(RESET, WHITE, BLACK);
	}
	return 0;
}

int print_menu(char *array[], int n_options, char *title)
{	int choice, i;
	for(i = 0;i < n_options; ++i)
		printf("%d.%s\n", i, array[i]);
	printf("%s", title);
	scanf("%d", &choice);
	return choice;
}		
void textcolor2(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}


void textcolor(int fg, int bg)
{
	printf("%c[0;%d;%dm", 0x1B, fg + 30, bg + 40);
}

void textreset()
{

	/* Command is the control command to the terminal */
	printf("%c[0m", 0x1B);
	
}

int main(int argc, char * argv[])
{
	int mode = -1;
	if (argc == 2) {
		if (!strcmp(argv[1], "-h")) {
			printf("usage: %s -[h, mode [0,1], menu]\n", argv[0]);
			printf("default mode is 0\n");
			return 0;
		}
		else if (!strcmp(argv[1],"-menu")) return menu();
		else if (!strcmp(argv[1],"-mode")) puts("mode requires an argument, see -h");
		else puts("invalid argument");
		puts("defaulting to -mode 0");
		mode = 0;
	}
	else if (argc == 3) {
		if (!strcmp(argv[1],"-mode")) {
			mode = atoi(argv[2]);
		}
		else mode = 0;
	}
	else {
		puts("defaulting to -mode 0");
		mode = 0;
	}
	if (mode == 0) {
		for(int iii = 0;iii < 8;iii++) for(int ii = 0;ii < 8;ii++)
		{
			textcolor(ii, iii);	
			printf(" In color: fg = %d, bg = %d \n", ii, iii);
		}
		textreset();
	}
	else if (mode == 1) {
		for(int ii = 0;ii < 8;ii++) for(int iii = 0;iii < 8;iii++)
		{
			textcolor(ii, iii);	
			printf(" In color: fg = %d, bg = %d \n", ii, iii);
		}
		textreset();
	}
	else puts("invalid mode");
	Garbage_Collector_Shutdown();
	return 0;
}
