#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>

void PerformServerTask(int *newsockfd) {
	
	printf("SENDING TIME AND PID TO CLIENT %d\n", *newsockfd);
	time_t now = time(0);
	struct tm * time_info = localtime(&now);
	char * time_str = asctime(time_info);
	time_str[strlen(time_str) - 1] = '\0';
	int pid = getpid();
	char buf[256] = "";
	sprintf(buf, "The server time is %s and the server pid is %d", time_str, pid);
	write(*newsockfd, buf, sizeof(buf));
}

void CreateServerSocket() {

	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	int result;
	fd_set readfds, testfds;

	
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = htons(10200);
	server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
	
	listen(server_sockfd, 5);
	FD_ZERO(&readfds);
	FD_SET(server_sockfd, &readfds);

	while(1) {
		char ch;
		int fd, nread;
		testfds = readfds;
		printf("server waiting\n");
		result = select(FD_SETSIZE, &testfds, (fd_set *)0, (fd_set *)0, (struct  timeval *)0);
		
		

		if (result < 1) {
			perror("server error");
			exit(1);
		}

		for (fd = 0; fd < FD_SETSIZE; fd++) {
			if (FD_ISSET(fd, &testfds)) {

				if (fd == server_sockfd) {
					client_len = sizeof(client_address);
					client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, 
						&client_len);
					FD_SET(client_sockfd, &readfds);
					printf("adding client on fd%d\n", client_sockfd);
					PerformServerTask(&client_sockfd);
				}
				
				else {
					ioctl(fd, FIONREAD, &nread);
					if (nread == 0) {
						close(fd);
						FD_CLR(fd, &readfds);
						printf("removing client on fd%d\n", fd);
					}
				}

			}
		}
	}
}

int main(int argc, char const *argv[])
{
	
	CreateServerSocket();
	return 0;
}