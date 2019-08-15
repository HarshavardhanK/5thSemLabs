#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <limits.h>
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
	
	printf("\nENTER NUM1\t");
	int num1;
	scanf("%d", &num1);
	write(*sockfd, &num1, sizeof(num1));
	printf("\nENTER NUM2\t");
	int num2;
	scanf("%d", &num2);
	write(*sockfd, &num2, sizeof(num2));
	printf("\nENTER OPERATION\t");
	char op;
	getchar();
	scanf("%c", &op);	
	write(*sockfd, &op, sizeof(op));
	printf("\nANSWER SENT BACK FROM SERVER IS .... \t");
	int value;
	read(*sockfd, &value, sizeof(value));
	if (value == INT_MAX)
		printf("MATH ERROR\n");
	else
		printf("%d\n", value);
}

int main(int argc, char const *argv[])
{
	int len,result,sockfd,n=1;
	struct sockaddr_in address;

	CreateClientSocket(&sockfd, &address, &len, &result);

	PerformClientTask(&sockfd);
	return 0;
}