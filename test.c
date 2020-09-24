#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
# include <inttypes.h>
# define FT_BIT(a) (1 << a)
# define BUF_SIZE 4096

#include <ncurses.h>

int main()
{
    // const int width = 100;
    // const int height = 40;

    // if (!initscr())
    // {
    //     fprintf(stderr, "Error initialising ncurses.\n");
    //     exit(1);
    // }

    // initscr();
    // curs_set(0);
    // refresh();

    // int offsetx = (COLS - width) / 2;
    // int offsety = (LINES - height) / 2;

    // WINDOW *win = newwin(height, width, offsety, offsetx);

    // char hello[] = "Hello, world!";

    // mvaddstr(LINES/2, (COLS-strlen(hello))/2, hello);
    // box(win, 0, 0);

    // wrefresh(win);
    // getch();
    // //epfepgro

    // delwin(win);
    // endwin();
    int i = 12;
    printf("%d\n", FT_BIT(((4 & 0x0C) >> 2)));
}

// 10011100
// 11000000 // 00110000 // 00001100
// 00000010

// 01010100
// 11000000
// 00110000
// 00001100