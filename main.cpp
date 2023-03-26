#include "Header.h"
#include <ncurses.h>

int main(void) {
    WINDOW *Windows;

    initscr();

    if (has_colors() == FALSE) {
        puts("Terminal does not support colors!");
        endwin();
        return 1;

    } else {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_CYAN);
        init_pair(2, COLOR_RED, COLOR_CYAN);
        init_pair(3, COLOR_BLACK, COLOR_CYAN);
    }

    refresh();

    Windows = newwin(50, 150, 0, 0);
    wbkgd(Windows, COLOR_PAIR(1));
    menu(Windows);
    wrefresh(Windows);

    getch();
    endwin();
}
