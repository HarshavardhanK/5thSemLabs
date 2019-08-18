#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char** argv) {

    char buffer[256];

    struct sockaddr_in server_add, client_add;

    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);

    server_add.sin_family = AF_INET;
    server_add.sin_port = htons(3000);
    server_add.sin_addr.s_addr = inet_addr("127.0.0.1");

    int bind_status = bind(sock_fd, (struct sockaddr*) &server_add, sizeof(server_add));

    socklen_t client_length = sizeof(client_add);
    int receive = recvfrom(sock_fd, buffer, sizeof(buffer), 0, (struct sockaddr*) &client_add, &client_length);

    printf("the server send is %s\n", buffer); 

    int _send_ = sendto(sock_fd, buffer, sizeof(buffer), 0, (struct sockaddr*) &client_add, client_length);

    return 0;



    
}