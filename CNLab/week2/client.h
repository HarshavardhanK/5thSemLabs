#ifndef CLIENT_H
#define CLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define CHAR 1
#define INT 0

//remove buffer from args to solve sorting q3 problem

void print_buffer(int* buffer, int buffer_size) {

    for(int i = 0; i < buffer_size; i++) {
        printf("%d ", buffer[i]);
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

int create_client(char* ip_addr, int port_no, int type, void** buffer, int buffer_size, int (*client_task) (void*, int)) {

    int len;
    int result;
    int sockfd;
    int n = 1;

    void* result_buffer;

    cast_buffer(type, buffer, buffer_size);

    struct sockaddr_in address;

    //create a socket for the client
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //Name the socket as agreed with server
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip_addr);
    address.sin_port = htons(port_no);

    len = sizeof(address);

    //Connect your socket to the server's socket
    result = connect(sockfd, (struct sockaddr*)& address, len);

    if(result == -1) {
        perror("\nClient error\n");
        //exit(1);
        return -1;
    }

    //print_buffer(*buffer, buffer_size);

    if(type == INT) {

        send(sockfd, buffer, buffer_size * sizeof(int), 0);

        recv(sockfd, &result_buffer, buffer_size * sizeof(int), 0);

    } else if(type == CHAR) {

        send(sockfd, buffer, buffer_size * sizeof(char), 0);

        recv(sockfd, &result_buffer, buffer_size * sizeof(char), 0);\

    }

    client_task(result_buffer, buffer_size);

    return 1;
}

#endif