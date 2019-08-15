#ifndef SERVER_H
#define SERVER_H

#include <sys/types.h>
#include <sys/socket.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netinet/in.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <unistd.h>

#define CHAR 1
#define INT 0

void print_buffer(void* buffer, int buffer_size, int TYPE) {

    if(TYPE == CHAR) {
        
        for(int i = 0; i < buffer_size; i++) 
            printf("%c", ((char*)buffer)[i]);

    } else {
        for(int i = 0; i < buffer_size; i++) 
            printf("%d ", ((int*)buffer)[i]);
    }

    printf("\n");
}

void cast_buffer(int type, void* buffer, int buffer_size) {

    if(type == CHAR) {
        buffer = (char*) malloc(sizeof(char) * buffer_size);

    } else if(type == INT) {
        buffer = (int*) malloc(sizeof(int) * buffer_size);
    }

}

//handle buffer_size param for q3

int server(char* ip, int port, int size, void (*server_task) (int*, int)) {

    int *buffer = (int*) malloc(sizeof(int) * size);

    int server_sockf_fd, client_sockfd;

    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t server_addr_len, client_addr_len;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    server_addr_len = sizeof(server_addr);

    server_sockf_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(bind(server_sockf_fd, (struct sockaddr*) &server_addr, server_addr_len) < 0) {
        perror("failed to bind");
        return 1;
    }

    listen(server_sockf_fd, 5);

    fd_set read_fds;

    FD_ZERO(&read_fds);
    FD_SET(server_sockf_fd, &read_fds);

    while(1) {

        fd_set test_fds;
        test_fds = read_fds;

        printf("Listening on %s PORT %d || server waiting..\n", ip, port);

        if(select(FD_SETSIZE, &test_fds, (fd_set*) 0, (fd_set*) 0, (struct timeval *) 0) < 0) {
            perror("failed to select");
            return 1;
        }

        //once selected, check which descriptor the server is on

        for(int fd = 0; fd < FD_SETSIZE; fd++) {

            if(FD_ISSET(fd, &test_fds)) {

                if(fd == server_sockf_fd) {

                    client_addr_len = sizeof(client_addr_len);

                    client_sockfd = accept(server_sockf_fd, (struct sockaddr*) &client_addr, &client_addr_len);

                    FD_SET(client_sockfd, &read_fds);

                    printf("\nAdding client on %d\n", client_sockfd);

                } else {
                    int nread;

                    ioctl(fd, FIONREAD, &nread);

                    if(nread == 0) {

                        close(fd);
                        FD_CLR(fd, &read_fds);

                        printf("\nRemoving client on fd %d\n", fd);

                    } else {

                        while(recv(client_sockfd, &buffer, sizeof(int) * size, 0) > 0) {

                            printf("\nreceviing data\n");

                            server_task(buffer, size);

                            write(fd, &buffer, sizeof(int) * 10);
                        }

                    }

                }

            }
        }
    }

    return 0;

}
#endif