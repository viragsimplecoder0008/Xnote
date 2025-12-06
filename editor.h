#ifndef EDITOR_H
#define EDITOR_H

void insert_char(int ch);
void insert_tab();
void new_line();
void delete_char();
void delete_current_line();
extern int cursor_x, cursor_y;

#endif
