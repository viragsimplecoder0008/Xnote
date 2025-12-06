#include <ncurses.h>
#include <stdlib.h>
#include <string.h>  // for strcpy, strlen, strdup
#include <ctype.h>   // for isprint
#include "file.h"    // for load_file(), detect_syntax(), filename, lines
#include "editor.h"
#include "screen.h"


int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    strcpy(filename, argv[1]);
    detect_syntax();

    for (int i = 0; i < 5000; i++)
        lines[i] = strdup("");

    load_file();

    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);

    if (has_colors()) {
        start_color();
        use_default_colors();
        init_pair(1, COLOR_WHITE, -1);
        init_pair(2, COLOR_CYAN, -1);
        init_pair(3, COLOR_YELLOW, -1);
    }

    int ch;
    while (1) {
        draw_screen();
        ch = getch();
        switch(ch) {
            case KEY_UP: if (cursor_y > 0) cursor_y--; break;
            case KEY_DOWN: if (cursor_y < line_count - 1) cursor_y++; break;
            case KEY_LEFT: if (cursor_x > 0) cursor_x--; break;
            case KEY_RIGHT: {
                int len = strlen(lines[cursor_y]);
                if (cursor_x < len) cursor_x++;
            } break;
            case '\n': new_line(); break;
            case KEY_BACKSPACE:
            case 127:
            case '\b': delete_char(); break;
            case 9: insert_tab(); break;
            case 19: { save_file(); mvprintw(LINES-2,0,"Saved!"); clrtoeol(); refresh(); napms(800);} break;
            case 17: { mvprintw(LINES-2,0,"Quit? Press Y to confirm"); clrtoeol(); refresh(); int confirm=getch(); if(confirm=='y'||confirm=='Y'){endwin(); exit(0);} } break;
            case 18: command_menu(); break;
            default: if(isprint(ch)) insert_char(ch); break;
        }
    }

    endwin();
    return 0;
}
