#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void CreateClientSocket(int *sockfd, 
	struct sockaddr_in * address, int * len, int *result){

	*sockfd = socket(AF_INET, SOCK_STREAM, 0);

	address->sin_family = AF_INET;
	address->sin_addr.s_addr = inet_addr("127.0.0.1");
	address->sin_port = htons(10200);
	*len = sizeof(*address);
	
	*result = connect(*sockfd, (struct sockaddr*)address, *len);
	if(*result == -1){
		perror("\nCLIENT ERROR");
		exit(1);
	}
}

void PerformClientTask(int * sockfd){
	// You can now read and write via sockfd
	while(1) {
		char ch[256] = "",buf[256] = "";
		printf("\nENTER STRING\t");
		gets(ch);
		ch[sizeof(ch)] = '\0';
		write(*sockfd, ch, strlen(ch));
		printf("STRING SENT BACK FROM SERVER IS .... ");
		read(*sockfd, buf, sizeof(buf));
		puts(buf);
		if (!strcmp(buf,"QUIT"))
			break;
	}
}

int main(int argc, char const *argv[])
{
	int len,result,sockfd,n=1;
	struct sockaddr_in address;

	CreateClientSocket(&sockfd, &address, &len, &result);

	PerformClientTask(&sockfd);
	return 0;
}