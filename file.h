#ifndef FILE_H
#define FILE_H

void load_file();
void save_file();
void detect_syntax();

extern char *lines[];
extern int line_count;
extern char filename[256];
extern int is_python, is_ruby, is_c, is_cpp;

#endif
