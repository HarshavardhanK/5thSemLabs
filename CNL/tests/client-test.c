#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int create_client(char* ip, unsigned short int port) {

    struct sockaddr_in add;
    add.sin_family = AF_INET;
    add.sin_port = htons(port);
    add.sin_addr.s_addr = inet_addr(ip);

    int _sock_ = socket(AF_INET, SOCK_STREAM, 0);

    if(connect(_sock_, (struct sockaddr*) &add, sizeof(add)) < 0) {
        perror("error");
        return -1;
    }

    return _sock_;
}

void client_task(int sockfd, char ch) {

    write(sockfd, &ch, sizeof(ch));
    char *mess = (char*) malloc(sizeof(char) * 1024);

    read(sockfd, mess, sizeof(mess));

    printf("%s\n", mess);
}

int main() {

    int sockfd = create_client("172.16.58.36", 9734);

    if(sockfd != -1) {
        client_task(sockfd, 'b');
       // printf("successfull");

    } else {
        printf("\nfailed\n");
    }

    return 0;
    
}