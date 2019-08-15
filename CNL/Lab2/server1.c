#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORTNO 10200

void PerformServerTask(int *newsockfd) {
	int n;
	char buf[256] = "";
	n = read(*newsockfd, buf, sizeof(buf));
	printf("\nMessage from Client %s\n", buf);
	n = write(*newsockfd, buf, sizeof(buf));
	close(*newsockfd);
	exit(0);
}

void CreateServerSocket() {
	int sockfd, newsockfd, portno, clilen, n = 1;
	struct sockaddr_in seraddr, cliaddr;
	int i, value;
	char buf[256];
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
	listen(sockfd, 5);
	while(1) {
		
		clilen = sizeof(clilen);
		newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
		if (fork() == 0) {
			PerformServerTask(&newsockfd);
		}
		else {
			close(newsockfd);
		}
	}
}

int main()
{
	CreateServerSocket();
	return 0;
}