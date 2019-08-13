#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define PORTNO 10200

char *strupr(char *str)
{
  unsigned char *p = (unsigned char *)str;

  while (*p) {
     *p = toupper((unsigned char)*p);
      p++;
  }

  return str;
}

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
    server_addr.sin_port = htons(10200);

    int bind_status = bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr));
    int listen_status = listen(sockfd, 5);

    while(1) {
        char buffer[512];
        printf("Server waiting...\n");

        //Accept an incoming connection
        clilen = sizeof(client_addr);

        new_sock_fd = accept(sockfd, (struct sockaddr*)& client_addr, &clilen);

        //Read and write to client on 

        n = read(new_sock_fd, buffer, sizeof(buffer));
        printf("message from client %s\n", buffer);

        //strcpy(buffer, strupr(buffer));
        //strupr(buffer);
        printf("buffer is %s\n", buffer);

        //strupr for #3

        if(strcmp(buffer, "quit") == 0) {
            printf("Quitting\n");
            exit(0);
        }

        n = write(new_sock_fd, strupr(buffer), sizeof(buffer));
    }
    printf("Success\n");

    return 0;


}

