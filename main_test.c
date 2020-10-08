#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
# include <inttypes.h>

#include <ncurses.h>
#define SIZE 4096

int main()
{
    char arena[SIZE] = {0};
    const int width = getcurx(stdscr);
    const int height = getcury(stdscr);

    if (!initscr())
    {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(1);
    }

    initscr();
    curs_set(0);
    refresh();

    int offsetx = (COLS - width) / 2;
    int offsety = (LINES - height) / 2;

    WINDOW *wbox = newwin(66, 195, 1, 0);
    WINDOW *wtab = newwin(66, 50, 1, 195);
    wattron(wbox, A_BOLD | A_BLINK);
    box(wbox, 0, 0);
    box(wtab, 0, 0);
    wrefresh(wbox);
    wrefresh(wtab);

    WINDOW *warena = newwin(64, 192, 2, 2);
    wrefresh(warena);

    int i = 0;
    while (i < SIZE)
    {
        wprintw(warena, "%.2x ", arena[i]);
        i++;
    }
    wrefresh(warena);

    getch();

    delwin(warena);
    delwin(wtab);
    endwin();
}
