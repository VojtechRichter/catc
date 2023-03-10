#include "parse_args.h"

InputFile* parse_args(int argc, char** argv) {
    if (argc < 2) {
        display_usage();
        exit(1);
    }

    char* file_path = argv[1];
    InputFile* ifile = malloc(sizeof(InputFile)); 

    ifile->file_path = file_path;

    return ifile;
}

void read_input_file(const char* file_path, InputFile* input_file) {
    FILE* f = fopen(file_path, "rb");
    if (!f) {
        fprintf(stderr, "Invalid file\n");
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char* content = malloc(fsize + 1);
    fread(content, fsize, 1, f);
    fclose(f);

    content[fsize] = 0;

    input_file->content = content;
    input_file->file_size = fsize;

}

void display_usage() {
    printf("Usage: \n\n\tcatc [FILENAME]\n\tcatc [OPTION] ... [FILENAME]\n\n");
}

char* get_file_ext(char* file_path) {
    char* _fpath = file_path;
    char* file_name = strtok(_fpath, "\\");
    while (file_name != NULL) {
        file_name = strtok(NULL, "\\");
    }

    char* next_char = NULL;
    char* file_ext = strtok_s(file_name, ".", &next_char);
    file_ext = strtok_s(NULL, ".", &next_char);

    return file_ext;
}

void print_file_content(InputFile* ifile) {
    printf("-------------------SOF-------------------\n");
    printf("%s", ifile->content);
    printf("-------------------EOF-------------------");
}