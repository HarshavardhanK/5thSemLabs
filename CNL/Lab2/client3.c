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
	
	printf("\nENTER NUM OF ELEMENTS\t");
	int size;
	scanf("%d", &size);
	write(*sockfd, &size, sizeof(size));
	printf("\nENTER %d ELEMENTS\t", size);
	int arr[size];
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
	write(*sockfd, arr, sizeof(arr));
	printf("\nSORTED SENT BACK FROM SERVER IS .... ");
	read(*sockfd, arr, sizeof(arr));
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	int pid;
	read(*sockfd, &pid, sizeof(pid));
	printf("\nThe PID is %d\n", pid);
}

int main(int argc, char const *argv[])
{
	int len,result,sockfd,n=1;
	struct sockaddr_in address;

	CreateClientSocket(&sockfd, &address, &len, &result);

	PerformClientTask(&sockfd);
	return 0;
}