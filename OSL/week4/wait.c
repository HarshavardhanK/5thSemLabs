#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main() {

    int status;

    pid_t pid;

    pid = fork();

    if(pid == -1) {
        printf("\nerror child not created\n");

    } else if(pid == 0) {
        printf("Child program\n");
        return 1;

    } else {

        wait(&status);
        printf("\nparent");
        printf("\nchild returned: %d\n", status);
    }

    return 0;
}