#include <stdio.h>
#include <conio.h>

int main ()
{
	int ch;
	printf("type \"quit\" to exit the program\n");
	while ((ch = getch()))
	{
		printf("%c is %d\n", ch, ch);
		// detect quit
		if (ch == 'q') {
			ch = getch();
			printf("%c is %d\n", ch, ch);
			if (ch == 'u') {
				ch = getch();
				printf("%c is %d\n", ch, ch);
				if (ch == 'i') {
					ch = getch();
					printf("%c is %d\n", ch, ch);
					if (ch == 't') {
						break;
					}
				}
			}
		}
		
	}
	return 0;
}
