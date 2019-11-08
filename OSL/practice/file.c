#include <stdio.h>
#include <fcntl.h>

int main() {

    FILE* fp = fopen("hello.txt", "a+");

    fprintf(fp, "%s\n", "sup bitch lmao");

    fclose(fp);

    fp = fopen("hello.txt", "r");

    char c = fgetc(fp);

    while( c != EOF ) {
        printf("%c", c);
        c = fgetc(fp);
    }

    fclose(fp);

    return 0;
}