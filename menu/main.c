#include <stdio.h>

int menu(int lenoitems, char* items[]);

int main(void) {
	char* items[] = {"option", "nextop", "thenext", "the end"};
	int lenoitems = sizeof(items)/sizeof(items[0]);
	int choice = menu(lenoitems, items);
	printf("%s\n", items[choice]);
	return 0;
}
