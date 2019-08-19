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

	// Create a socket for the client
	*sockfd = socket(AF_INET, SOCK_STREAM, 0);

	// Name the socket as agreed with the server
	address->sin_family = AF_INET;
	address->sin_addr.s_addr = inet_addr("127.0.0.1");
	address->sin_port = htons(10200);
	*len = sizeof(*address);

	// Connect your socket to the server socket
	*result = connect(*sockfd, (struct sockaddr*)address, *len);
	if(*result == -1){
		perror("\nCLIENT ERROR");
		exit(1);
	}
}

void encrypt(char ch[], int size) {
	const int KEY = 4;
	for (int i = 0; i < size; i++) {
		ch[i] += KEY;
	}
}

void PerformClientTask(int * sockfd){
	// You can now read and write via sockfd
	char ch[256];
	printf("\nENTER STRING\t");
	gets(ch);
	ch[strlen(ch)] = '\0';
	encrypt(ch, strlen(ch));
	write(*sockfd, ch, strlen(ch));
}

int main(int argc, char const *argv[])
{
	int len,result,sockfd,n=1;
	struct sockaddr_in address;

	CreateClientSocket(&sockfd, &address, &len, &result);

	PerformClientTask(&sockfd);
	return 0;
}