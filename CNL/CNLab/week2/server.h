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

void print_buffer(int *buffer, int buffer_size) {

    for(int i = 0; i < buffer_size; i++) {
        printf("%d ", buffer[i]);
    }

    printf("\n");
}

//handle buffer_size param for q3

int create_server(char* ip_addr, int port_no, int buffer_size, int (*server_task) (int* buffer, int buffer_size)) {
    
    int server_sockfd, client_sockfd;
    socklen_t server_len, client_len;

    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    int result;

    fd_set readfds, test_fds;

    //
    int buffer[10];

    //Create and name a socket for the server
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;

    server_address.sin_addr.s_addr = inet_addr(ip_addr);

    server_address.sin_port = htons(port_no);
    server_len = sizeof(server_address);

    bind(server_sockfd, (struct sockaddr*) &server_address, server_len);

    //create a connection queue and initialize readfds from server_sockfd
    listen(server_sockfd, 5);
    FD_ZERO(&readfds);
    FD_SET(server_sockfd, &readfds);

    while(1) {
        
        char ch;
        int fd, nread;

        test_fds = readfds;

        printf("Server waiting...");
        printf("\n");

        result = select(FD_SETSIZE, &test_fds, (fd_set*) 0, (fd_set*) 0, (struct timeval*) 0);

        printf("Hello\n");

        if(result < 1) {
            perror("server error");
            exit(1);
        }

        printf("\n");

        printf("FD_SETSIZE %d\n", FD_SETSIZE);

        for(fd = 0; fd < FD_SETSIZE; fd++) {

            if(FD_ISSET(fd, &test_fds)) {

                char client__sockfd[5];

                if(fd == server_sockfd) {

                    client_len = sizeof(client_address);
                    client_sockfd = accept(server_sockfd, (struct sockaddr* ) & client_address, &client_len);

                    FD_SET(client_sockfd, &readfds);
                    printf("adding client on fd %d\n", client_sockfd);
                    
                } else {

                    ioctl(fd, FIONREAD, &nread);

                    if(nread == 0) {

                        close(fd);
                        FD_CLR(fd, &readfds);
                        printf("removing client on fd%d\n", fd);

                    } else {

                        int read_size;

                       // bzero(buffer, buffer_size);

                        while ((read_size = recv(client_sockfd, &buffer, buffer_size * sizeof(int), 0)) > 0) { 

                            print_buffer(buffer, buffer_size);
  
                            server_task(buffer, 10); 
  
                            write(client_sockfd, buffer, buffer_size * sizeof(int)); 
                         } 

                        //write(fd, buffer, 10);
                        //write(fd, getpid(), sizeof(int));
                    }
                }
            }
        }
    }

    return 1;
}

#endif