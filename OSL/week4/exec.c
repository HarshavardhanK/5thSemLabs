#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {

    pid_t pid;

    pid = fork();

    if(argv[1] == NULL || argv[2] == NULL) {
        printf("enter binary executable\n");
        return 1;
    }

    if(pid < 0) {
        printf("Fork failed\n");
        return -1;

    } else if(pid == 0) {
        execlp(argv[1], argv[1], argv[2], NULL);

    } else {
        wait(NULL);
        printf("Child complete\n");
    }

    return 0;
}