#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(3000);
    address.sin_addr.s_addr = inet_addr("127.0.0.1");

    socklen_t address_len = sizeof(address);


    for(int i = 0; i < 2; i++) {

       // printf("\nEnter an array: \n");

        int arr[] = {15,2};

        /*for(int j = 0; i < 0; j++) {
            //scanf("%d", &arr[j]);
            gets(arr[i]);
        }*/

        int _send_ = sendto(sockfd, arr, sizeof(arr), 0, (struct sockaddr*) &address, sizeof(address));
    }

    int *result = (int*) malloc(sizeof(int) * 4);

    int _recv_ = recvfrom(sockfd, result, sizeof(result), 0, (struct sockaddr*) &address, &address_len);

    for(int i = 0; i < 2; i++) {
        for(int j =0; j < 2; j++)
            printf("%d ", result[i * 2 + j]);
        
        printf("\n");
    }

    return 0;

}