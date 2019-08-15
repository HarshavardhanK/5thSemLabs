#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#define PORTNO 10200

void upper_string(char s[]) {
	int c = 0;   
	while (s[c] != '\0') {
		if (s[c] >= 'a' && s[c] <= 'z') {
			s[c] = s[c] - 32;
		}
		c++;
	}
}

void PerformServerTask(int * newsockfd, struct sockaddr_in cliaddr){

	while (1) {
		char buf[256] = "";
		read(*newsockfd, buf, sizeof(buf));
		upper_string(buf);
		printf("\nMessage from Client is: %s\n", buf);
		printf("Client IP: %s and Client port: %d\n", inet_ntoa(cliaddr.sin_addr), (int) ntohs(cliaddr.sin_port));
		write(*newsockfd, buf, sizeof(buf));
		if (!strcmp(buf,"QUIT")) {
			break;
		}
	}
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
	printf("server waiting");

	clilen = sizeof(clilen);
	newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr,
		&clilen);
	PerformServerTask(&newsockfd, cliaddr);
	close(sockfd);
}

int main(){
	
	CreateServerSocket();

	return 0;
}
