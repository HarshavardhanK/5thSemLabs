#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void _pipe_() {

    int fd[2];

    char buff[1025];
    char* data = "what message\n";

    pipe(fd);
    write(fd[1], data, strlen(data));

    int read_des = read(fd[0], buff, 1024);

    if(read_des >= 0) {
        buff[read_des] = '\0';
        printf("Read from IPC message %s\n", buff);

    } else {
        printf("err\n");
    }

   
}

int main() {

    _pipe_();

    return 0;

}