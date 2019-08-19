#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#define PORTNO 10200

void decrypt(char buf[], int size) {
	const int KEY = 4;
	for (int i = 0; i < size; i++) {
		buf[i] -= KEY;
	}
}

void PerformServerTask(int * newsockfd, char buf[]){
	// Read and write to client_sockfd
	read(*newsockfd, buf, sizeof(buf));
	printf("\nMessage from Client %s\n", buf);
	decrypt(buf, strlen(buf));
	printf("\nDecrypted message is %s\n", buf);
	write(*newsockfd, buf, sizeof(buf));
}

void CreateServerSocket(){
	int sockfd, newsockfd, portno, clilen;
	struct sockaddr_in seraddr,cliaddr;
	int i,value;
	// Create an unnamed socket for the server
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	// Name the socket
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));

	// Create a connection queue and wait for clients
	listen(sockfd, 5);
	// while(1) {
		char buf[256];
		printf("server waiting");
		// Accept a connection
		clilen = sizeof(clilen);
		newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr,
			&clilen);
		PerformServerTask(&newsockfd, buf);
	// }
}

int main(){
	
	CreateServerSocket();

	return 0;
}
