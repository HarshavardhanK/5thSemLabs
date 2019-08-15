#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORTNO 10200

int compare (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void PerformServerTask(int *newsockfd) {
	int size;
	read(*newsockfd, &size, sizeof(size));
	int arr[size];
	read(*newsockfd, arr, sizeof(arr));
	printf("\nArray from Client \n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	qsort(arr, size, sizeof(int), compare);
	write(*newsockfd, arr, sizeof(arr));
	int pid = getpid();
	write(*newsockfd, &pid, sizeof(pid));
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