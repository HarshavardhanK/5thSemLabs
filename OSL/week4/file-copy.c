#include <stdio.h>

int main(int argc, char** argv) {

    if(argc < 3) {
        printf("error in parsing input\n");
        return 1;
    }

    FILE* from_file = fopen(argv[1], "r");
    FILE* to_file = fopen(argv[2], "w+");

    if(from_file == NULL) {
        printf("no such input file\n");
        return 1;
    }

    char c = fgetc(from_file);

    while(c != EOF) {
        fputc(c, to_file);
        c = fgetc(from_file);
    }

    printf("Successfully copied\n");

    return 0;
}