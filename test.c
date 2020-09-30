#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
# include <inttypes.h>
# define FT_BIT(a)  (1 << a)
# define MODX(x)    (x % 512)
# define BUF_SIZE   4096

#include <ncurses.h>

void    set_value_by_addres(uint8_t *buf, int addres, int value, int size)
{
    uint8_t *ptr;
    int     i;

    i = size;
    ptr = (uint8_t *)&value;
    while (--i >= 0)
    {
        buf[addres + i] = *ptr++;
    }
}

int  bytecode_to_int(uint8_t *buffer, int size)
{
    int result;
    int sign;
    int i;

    i = 0;
    sign = 0;
    sign = buffer[0] & 0x80;
    result = 0;
    while (i < size)
        result = result * 256 + (sign ? buffer[i++] ^ 0xff : buffer[i++]);
    return (sign ? ~result : result);
}

// int main()
void    print_arena(uint8_t *arena, int size)
{
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

    WINDOW *win = newwin(height, width, offsety, offsetx);

    for (size_t i = 0; i < size; i++)
    {
        if (arena[i] <= 0x10)
            printw("0%x ", arena[i]);
        else
            printw("%x ", arena[i]);
        if (((i + 1) % 63) == 0)
            printw("\n");
    }

    // for (size_t i = 0; i < size; i++)
    // {
    //     if (arena[i] <= 0x10)
    //         printw("0%x ", arena[i] | );
    //     else
    //         printw("%x ", arena[i]);
    //     if (((i + 1) % 63) == 0)
    //         printw("\n");
    // }
    // mvaddstr(LINES/2, (COLS-strlen(hello))/2, hello);
    // box(win, 0, 0);

    wrefresh(win);
    getch();

    delwin(win);
    endwin();
}

int main()
{
    int16_t val = -365;
    uint8_t buf[4096] = {0};
    // set_value_by_addres(buf, 0, val, 2);
    // print_arena(buf, 4096);
    // int res = bytecode_to_int(buf + 0, 2);
    // printf("res %d", res);
    // printf("res %d | MODX(res) = %d\n", res, MODX(res));
}

// 10011100
// 11000000 // 00110000 // 00001100
//  00000000 10000000
//  11111111 11111110
//  00000000 10000000
//

// 11111111
// 11111111
// 00000000
// 00000000