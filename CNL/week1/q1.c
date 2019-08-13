#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORTNO 10200

int main(int argc, char** argv) {

    int sockfd;
    int new_sock_fd;

    int clilen;
    int n = 1, i, value;

    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;


    //create an unnamed socket for the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //name the socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("172.16.48.92");

    printf("Success\n");

    return 0;


}

