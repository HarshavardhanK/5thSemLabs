#include<stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORTNO 10200

void server_task(int *sockfd, int *newsockfd, char*ip, unsigned short int port) {

	char buffer[256];

	struct sockaddr_in client;
	client.sin_family = AF_INET;
	client.sin_port = htons(port);
	client.sin_addr.s_addr = inet_addr(ip);

	socklen_t client_len = sizeof(client_len);

	*newsockfd = accept(*sockfd, (struct sockaddr*) &client, &client_len);

	read(*newsockfd, buffer, sizeof(buffer));

	printf("\nMessage from clien is %s\n", buffer);

	write(*newsockfd, buffer, sizeof(buffer));

	exit(0);

}

void create_server(char* ip, unsigned short int port) {

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = inet_addr(ip);

	if(bind(sockfd, (struct sockaddr*) &server, sizeof(server)) < 0) {
		printf("cannot bind\n");
		exit(-1);
	}

	listen(sockfd, 5);

	int newsockfd;

	while(1) {

		if(fork() == 0) {

			server_task(&sockfd, &newsockfd, ip, port);

			close(newsockfd);

			exit(0);

		} else {

			close(newsockfd);
		}
	}
}

int main() {

	create_server("127.0.0.1", 3000);

	return 0;
}