#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORTNO 10200

void remove_duplicate(char s[], int size, char new_str[]) {
	char words[10][30];
	int j = 0, k = 0;
	for (int i = 0; i < size; i++) {
		if (s[i] == ' ') {
			words[j][k] = '\0';
			j++;
			k = 0;
		} else {
			words[j][k++] = s[i];
		}
	}
	words[j][k] = '\0';
	for (int i = 0; i < j; i++) {
		for (int k = i + 1; k <= j; k++) {
			if (!strcmp(words[i], words[k])) {
				words[k][0] = '\0';
			}
		}
	}
	strcpy(new_str, words[0]);
	for (int i = 1; i <= j; i++) {
		if (words[i][0] != '\0') {
			strcat(new_str, " ");
			strcat(new_str, words[i]);
		}
	}
	strcat(new_str, "\0");
}

void PerformServerTask(int *newsockfd) {
	while (1) {
		char buf[256] = "";
		read(*newsockfd, buf, sizeof(buf));
		char new_str[256];
		remove_duplicate(buf, strlen(buf), new_str);
		printf("\nMessage from Client is: %s\n", buf);
		printf("After processing %s\n", new_str);
		write(*newsockfd, new_str, sizeof(new_str));
		if (!strcmp(new_str,"Stop")) {
			break;
		}
	}
	close(*newsockfd);
	exit(0);
}

void CreateServerSocket() {
	int sockfd, newsockfd, portno, clilen, n = 1;
	struct sockaddr_in seraddr, cliaddr;
	int i, value;
	char buf[256];
	//create an unnamed socket for the server
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	//Name the socket
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));

	//Create a connection queue, ignore child exit details and wait for clients
	listen(sockfd, 5);
	while(1) {
		//Acccept the connection
		clilen = sizeof(clilen);
		newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
		//Fork to create a process for this client and perform a test to see whether
		//you're the parent or the child
		if (fork() == 0) {
			//If you're the child, you can now read/write to the client on newsockfd
			PerformServerTask(&newsockfd);
		}
		//Otherwise you must be the parent and your work for this client is finished
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