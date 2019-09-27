#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {

    int fd[2];

    char buff[256] = "Pipelining..";
    char data[256];

    pipe(fd);

    write(fd[1], buff, sizeof(buff));

    int _read_ = read(fd[0], data, 256);

    if(_read_ >= 0) {
        buff[_read_] = '\0';
        printf("Read %s from buffer\n", data);
    }

    return 0;
}