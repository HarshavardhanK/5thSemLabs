#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char** argv) {

    char *directory = (char*) malloc(sizeof(char) * 50);
    strcpy(directory, argv[1]);

    DIR* director_pointer = opendir(directory);

    if(director_pointer == NULL) {
        printf("No such directory\n");
        return 0;
    }

    struct dirent* dir;

    while(dir = readdir(director_pointer)) {
        printf("%s ", dir->d_name);
    }

    return 0;
    
}