#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {

    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in client_add;
    client_add.sin_family = AF_INET;
    client_add.sin_port = htons(3000);
    client_add.sin_addr.s_addr = inet_addr("127.0.0.1");

    char buffer[256];
    char buffer_1[256];

    printf("enter buffer: \n"); scanf("%s", buffer);

    socklen_t client_len = sizeof(client_add);

    int _send_ = sendto(sock_fd, buffer, sizeof(buffer), 0, (struct sockaddr*) &client_add, client_len);
    int _recv_ = recvfrom(sock_fd, buffer, sizeof(buffer), 0, (struct sockaddr*) &client_add, &client_len);

    printf("the server echo is %s: \n", buffer);

    return 0;
}