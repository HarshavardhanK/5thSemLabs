#include <stdio.h>

int characters(FILE* file) {

    int count = 0;

    printf("Counting char\n");

    if(!file) {
        printf("FILE error\n");
        return 0;
    }

    char c = fgetc(file);

    while(c != EOF) {
        count++;

        c = fgetc(file);
    }

    return count;
}

int words(FILE* file) {

    int count = 0;
    printf("Counting words\n");

    if(!file) {
        printf("FILE error\n");
        return 0;
    }

    char c = fgetc(file);

    while(c != EOF) {

        if(c == ' ' || c == '\n')
            count++;
        
        c = fgetc(file);
    }

    return count + 1;
}

int lines(FILE* file) {

    int count = 0;

    printf("Counting lines\n");

    if(!file) {
        printf("FILE error\n");
        return 0;
    }

    char c = fgetc(file);

    while(c != EOF) {

        if(c == '\n') {
            count++;
        }

        c = fgetc(file);
    }

    return count + 1;
}

int wc(char* type, FILE* file) {

    printf("%s command\n", type);

    if(type[1] == 'c') {
        return words(file);
    }

    if(type[1] == 'l') {
        return lines(file);
    }

    if(type[1] == 'w') {
        return words(file);
    }

    printf("undefined command\n");
    return 0;
}

int main(int argc, char** argv) {

    if(argc < 3) {
        printf("argument parsing error\n");
        return 1;
    }

    FILE* file = fopen(argv[2], "r");

    printf("%d\n", wc(argv[1], file));

    return 0;
}