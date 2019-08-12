#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#include "client.h"


void perform_client_task(int sockfd, char* buffer, int *value) {

    *value = read(sockfd, buffer, sizeof(buffer));
    puts(buffer);

}

/*int create_client(char* ip_addr, unsigned int port_no) {

    int len;
    int result;
    int sockfd;
    int n = 1;

    char ch[256];
    char buffer[512];


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

    puts("Enter string: ");
    gets(ch);
    ch[strlen(ch)] = '\0';

    write(sockfd, ch, strlen(ch));

    printf("String sent back from server is....|");

    while(n) {
        perform_client_task(sockfd, buffer, &n);
    }

    return 0;
} */



int main(int argc, char** argv) {

    create_client("127.0.0.1", 3000, perform_client_task, 1);
}