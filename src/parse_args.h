#ifndef CATC_PARSE_ARGS_H
#define CATC_PARSE_ARGS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

typedef enum OptionFlag OptionFlag;
enum OptionFlag {
    FLAG_FIRST_N_ROWS,
    FLAG_LAST_N_ROWS,
    FLAG_WHOLE_FILE,
    FLAG_NUMBER_LINES,
};

typedef struct InputFile InputFile;
struct InputFile {
    const char* file_path;
    const char* content;
    size_t file_size;
    const char* file_ext;
};

InputFile* parse_args(int argc, char** argv);
void read_input_file(const char* file_path, InputFile* input_file);
void print_file_content(InputFile* ifile);
void display_usage();
char* get_file_ext(char* file_name);

#endif // CATC_PARSE_ARGS_H