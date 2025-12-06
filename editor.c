#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "file.h"

int cursor_x = 0, cursor_y = 0;

void insert_char(int ch) {
    int len = strlen(lines[cursor_y]);
    if (len + 2 >= 2000) return;
    char *line = lines[cursor_y];
    memmove(&line[cursor_x + 1], &line[cursor_x], len - cursor_x + 1);
    line[cursor_x] = ch;
    cursor_x++;
}

void insert_tab() {
    for (int i = 0; i < 4; i++)
        insert_char(' ');
}

void new_line() {
    if (line_count >= 5000) return;
    char *current = lines[cursor_y];
    char *rest = strdup(current + cursor_x);
    current[cursor_x] = '\0';
    lines[cursor_y] = realloc(current, strlen(current) + 1);

    for (int i = line_count; i > cursor_y + 1; i--)
        lines[i] = lines[i - 1];
    lines[cursor_y + 1] = rest;
    line_count++;

    cursor_y++;
    cursor_x = 0;
}

void delete_current_line() {
    free(lines[cursor_y]);
    for (int i = cursor_y; i < line_count - 1; i++)
        lines[i] = lines[i + 1];
    line_count--;
    if (line_count == 0) {
        line_count = 1;
        lines[0] = calloc(1,1);
    }
    if (cursor_y >= line_count) cursor_y = line_count - 1;
    cursor_x = 0;
}

void delete_char() {
    if (cursor_x == 0) {
        delete_current_line();
        return;
    }
    char *line = lines[cursor_y];
    memmove(&line[cursor_x - 1], &line[cursor_x], strlen(line) - cursor_x + 1);
    cursor_x--;
}
