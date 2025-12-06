#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "file.h"
#include "editor.h"

int screen_row = 0;

void print_syntax(const char *text) {
    if ((is_python || is_ruby) && (strstr(text, "def ") || strstr(text, "class "))) {
        attron(COLOR_PAIR(2));
        printw("%s", text);
        attroff(COLOR_PAIR(2));
        return;
    }
    if ((is_c || is_cpp) && (strstr(text, "int ") || strstr(text, "char ") || strstr(text, "return"))) {
        attron(COLOR_PAIR(3));
        printw("%s", text);
        attroff(COLOR_PAIR(3));
        return;
    }
    printw("%s", text);
}

void draw_screen() {
    int cols = COLS;
    int max_display = LINES - 3;

    if (cursor_y < screen_row) screen_row = cursor_y;
    if (cursor_y >= screen_row + max_display) screen_row = cursor_y - max_display + 1;

    clear();
    mvprintw(0, (cols - strlen(filename)) / 2, "%s", filename);

    for (int i = 0; i < max_display && (i + screen_row) < line_count; i++) {
        move(i + 1, 0);
        printw("%3d  ", i + screen_row + 1);
        print_syntax(lines[i + screen_row]);
    }

    mvprintw(LINES - 1, 0, "^S Save   ^Q Quit   ^R Commands");
    move(cursor_y - screen_row + 1, cursor_x + 5);
    refresh();
}

void command_menu() {
    mvprintw(LINES - 2, 0, "Commands: S=Save Q=Quit");
    clrtoeol();
    refresh();
    int c = getch();
    if (c == 's' || c == 'S') {
        save_file();
        mvprintw(LINES - 2, 0, "Saved!");
        clrtoeol();
        refresh();
        napms(800);
    } else if (c == 'q' || c == 'Q') {
        mvprintw(LINES - 2, 0, "Quit? Press Y to confirm, any other key to cancel.");
        clrtoeol();
        refresh();
        int confirm = getch();
        if (confirm == 'y' || confirm == 'Y') {
            endwin();
            exit(0);
        }
    }
    mvprintw(LINES - 1, 0, "^S Save   ^Q Quit   ^R Commands");
    clrtoeol();
    refresh();
}
