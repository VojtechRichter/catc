#include "parse_args.h"

int main(int argc, char** argv) {
    InputFile* ifile = parse_args(argc, argv);

    read_input_file(ifile->file_path, ifile);

    print_file_content(ifile);

    free(ifile);

    return 0;
}