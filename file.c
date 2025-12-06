#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

#define MAX_LINES 5000
#define MAX_LEN 2000

char *lines[MAX_LINES];
int line_count = 0;
char filename[256];
int is_python = 0, is_ruby = 0, is_c = 0, is_cpp = 0;

void detect_syntax() {
    char *ext = strrchr(filename, '.');
    if (!ext) return;
    if (strcmp(ext, ".py") == 0) is_python = 1;
    if (strcmp(ext, ".rb") == 0) is_ruby = 1;
    if (strcmp(ext, ".c") == 0) is_c = 1;
    if (strcmp(ext, ".cpp") == 0 || strcmp(ext, ".c++") == 0) is_cpp = 1;
}

void load_file() {
    FILE *f = fopen(filename, "r");
    if (!f) {
        line_count = 1;
        lines[0] = calloc(1,1);
        return;
    }
    char buffer[MAX_LEN];
    while (fgets(buffer, MAX_LEN, f)) {
        buffer[strcspn(buffer, "\n")] = 0;
        lines[line_count++] = strdup(buffer);
    }
    fclose(f);
    if (line_count == 0) {
        line_count = 1;
        lines[0] = calloc(1,1);
    }
}

void save_file() {
    FILE *f = fopen(filename, "w");
    if (!f) return;
    for (int i = 0; i < line_count; i++)
        fprintf(f, "%s\n", lines[i]);
    fclose(f);
}
