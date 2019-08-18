#include <stdio.h>

int main(int argc, char** argv) {

    if(argc < 3) {
        printf("specify file and content");
        return 1;
    }

    FILE* fp;

    fp = fopen(argv[1], "w+");

    fputs(argv[2], fp);

    printf("written to file\n");
    fclose(fp);

    return 0;
}