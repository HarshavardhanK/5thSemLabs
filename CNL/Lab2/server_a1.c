#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORTNO 10200

void PerformServerTask(int *newsockfd) {
	//write to client_sockfd
	printf("SENDING TIME AND PID TO CLIENT %d\n", *newsockfd);
	time_t now = time(0);
	struct tm * time_info = localtime(&now);
	char * time_str = asctime(time_info);
	time_str[strlen(time_str) - 1] = '\0';
	int pid = getpid();
	char buf[256] = "";
	sprintf(buf, "The server time is %s and the server pid is %d", time_str, pid);
	printf("%s\n", buf);
	write(*newsockfd, buf, sizeof(buf));
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