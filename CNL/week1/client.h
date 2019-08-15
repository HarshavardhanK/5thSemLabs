
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


void print_buffer(int* buffer, int buffer_size) {

    for(int i = 0; i < buffer_size; i++) {
        printf("%d ", buffer[i]);
    }

    printf("\n");
}

int create_client(char* ip_addr, int port_no, int** buffer, int buffer_size, int input, int (*client_task) (int*, int)) {

    int len;
    int result;
    int sockfd;
    int n = 1;

    int result_buffer[buffer_size];

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

    if(input == 2) {
        *buffer = (char*) *(buffer);
    }

    if(buffer != NULL && *buffer != NULL) {

        print_buffer(*buffer, buffer_size);

        send(sockfd, buffer, buffer_size * sizeof(int), 0);

    } else {

        printf("\nInput buffer is empty you duffer\n");
    }

    client_task(result_buffer, buffer_size);
    recv(sockfd, &result_buffer, buffer_size * sizeof(int), 0);
    printf("\n%s\n", result_buffer);


    return 1;
}

#endif