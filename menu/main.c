#include <stdio.h>

int menu(int lenoitems, char* items[]);

int main(void) {
	char* items[] = {"option0", "option1", "option2", "option3"};
	int lenoitems = sizeof(items)/sizeof(items[0]);
	int choice = menu(lenoitems, items);
	printf("%s\n", items[choice]);
	return 0;
}
