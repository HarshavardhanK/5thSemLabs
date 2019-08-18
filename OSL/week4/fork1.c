#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv) {

    pid_t pid;
    char* message;

    int n;

    printf("forking\n");

    pid = fork();

    switch(pid) {

        case -1:
            perror("fork failed");
            return 1;
        case 0:
            message = "child";
            n = 5;
            break;

        default:
            message = "parent";
            n = 3;
            break;
    }

    for(; n > 0; n--) {
        printf("\n%s\n", message);
        sleep(1);
    }

    return 0;
}