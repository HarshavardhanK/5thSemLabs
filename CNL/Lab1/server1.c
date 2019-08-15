#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#define PORTNO 10200

void PerformServerTask(int * newsockfd, char buf[]){
	
	read(*newsockfd, buf, sizeof(buf));
	printf("\nMessage from Client %s\n", buf);
	write(*newsockfd, buf, sizeof(buf));
}

void CreateServerSocket(){
	int sockfd, newsockfd, portno, clilen;
	struct sockaddr_in seraddr,cliaddr;
	int i,value;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));

	listen(sockfd, 5);
	while(1) {
		char buf[256];
		printf("SERVER WAITING...");
		
		clilen = sizeof(clilen);
		newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr,
			&clilen);
		PerformServerTask(&newsockfd, buf);
	}
}

int main(){
	
	CreateServerSocket();

	return 0;
}
