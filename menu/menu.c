#include <ncurses.h>

int menu(int lenoitems, char* items[]) {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);

    int ch;
    int cn = 0;
    do {
        clear();
        printw("Press 'q' to exit. | pressed: %d\n\n", ch);
        if (ch == KEY_UP) {
        	cn--;
        } else if (ch == KEY_DOWN) {
            cn++;
        }

        if (cn < 0) {
        	cn = lenoitems - 1;
        } else if (cn >= lenoitems) {
        	cn = 0;
        }

        for (int i = 0; i < lenoitems; i++) {
        	printw("| ");
            if (cn == i) {
            	// removed the old colored option method 
            	attron(A_BOLD);
                printw("> %-15s", items[i]);
                attroff(A_BOLD);
            } else {
                printw("  %-15s", items[i]);
            }
            printw("|\n");
        }

        refresh();
    } while ((ch = getch()) != 'q' && ch != 10);

    endwin();
    return cn;
}
