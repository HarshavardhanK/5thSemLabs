#include <sys/types.h>
#include <sys/socket.h>
#include<stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

int main(int agrc, char** argv){

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
    address.sin_addr.s_addr = inet_addr("172.16.48.92");
    address.sin_port = htons(10200);

    len = sizeof(address);

    //Connect your socket to the server's socket
    result = connect(sockfd, (struct sockaddr*)& address, len);

    if(result == -1) {
        perror("\nClient error\n");
        exit(1);
    }

    printf("\nEnter string: ");
    scanf("%s", ch);
    ch[strlen(ch)] = '\0';

    write(sockfd, ch, strlen(ch));

    printf("String sent back from server is....|");

    while(n) {
        n = read(sockfd, buffer, sizeof(buffer));
        puts(buffer);
    }

    return 0;
}