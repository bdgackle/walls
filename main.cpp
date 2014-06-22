// Test program for curses
#include <curses.h>
#include <time.h>

int main()
{
    initscr(); // Initialize ncurses
    cbreak();  // Place input in c-break mode
    noecho();  // Prevent getch() from echoing
    keypad(stdscr, TRUE); // Make arrow keys work
    nodelay(stdscr, TRUE); // Make getch non blocking

    int x = COLS / 2;
    int y = LINES / 2;
    int dx = 0;
    int dy = 0;
    const char * str = "@";
    int input;

    struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = 200000000;

    while (1)
    {
        erase();
        mvaddstr(y, x, str);
        move(LINES - 1, COLS - 1);
        refresh();

        input = getch();

        if (input == KEY_UP )
        {
            dx = 0;
            dy = -1;
        }

        if (input == KEY_DOWN )
        {
            dx = 0;
            dy = 1;
        }

        if (input == KEY_LEFT )
        {
            dx = -1;
            dy = 0;
        }

        if (input == KEY_RIGHT )
        {
            dx = 1;
            dy = 0;
        }

        if ((dy == -1) && (y > 0))
            y--;

        if ((dy == 1) && (y < LINES - 1))
            y++;

        if ((dx == -1) && (x > 0))
            x--;

        if ((dx == 1) && (x < COLS -1))
            x++;

        nanosleep(&delay, NULL);
    }

    endwin();  // Return console to sane state

    return 0;
}


