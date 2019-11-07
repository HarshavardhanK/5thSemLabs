#include <stdio.h>

#include <sys/types.h>
#include <unistd.h>

int main() {

    pid_t pid;

    char* message;

    pid = fork();

    int n = 0;

    switch(pid) {

        case -1:
            printf("fork failed\n");
            return 1;
        
        case 0:
            message = "this is the child\n";
            execlp("/bin/ls", "ls", NULL);
            n = 3;
            break;
        
        default:
            message = "this is parent\n";
            n = 3;
            break;
    }

    for(; n >= 0; n--) {
        printf("%s\n", message);
    }

    return 0;
}
