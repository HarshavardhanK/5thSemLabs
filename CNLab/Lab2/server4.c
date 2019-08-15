#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORTNO 10200

int evaluate(int num1, int num2, char op) {
	switch(op) {
		case '+':
			return num1 + num2;
		case '-':
			return num1 - num2;
		case '*':
			return num1 * num2;
		case '/':
			if (num2 == 0)
				return INT_MAX;
			else
				return num1 / num2;
		default:
			return 0;						
	}
}

void PerformServerTask(int *newsockfd) {
	int num1;
	read(*newsockfd, &num1, sizeof(num1));
	int num2;
	read(*newsockfd, &num2, sizeof(num2));
	char op;
	read(*newsockfd, &op, sizeof(op));
	int value = evaluate(num1, num2, op);
	if (value != INT_MAX)
		printf("%d %c %d = %d\n",num1, op, num2, value);
	else
		printf("MATH ERROR\n");
	write(*newsockfd, &value, sizeof(value));
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