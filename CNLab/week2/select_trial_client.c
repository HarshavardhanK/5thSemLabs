#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

void print_array(int arr[], int size) {

    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int create_client(char* ip_addr, unsigned int port_no) {

    int len;
    int result;
    int sockfd;
    int n = 1;

    char ch[256];
    int buffer[10] = {4,5,1,2,3,9,10,6,12,56};
    int result_buffer[10];

    struct sockaddr_in address;

    //create a socket for the client
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //Name the socket as agreed with server
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip_addr);
    address.sin_port = htons(port_no);

    len = sizeof(address);

    //Connect your socket to the server's socket
    result = connect(sockfd, (struct sockaddr*)& address, len);

    if(result == -1) {
        perror("\nClient error\n");
        //exit(1);
        return -1;
    }


    send(sockfd, &buffer, 10 * sizeof(int), 0);

    recv(sockfd, &result_buffer, 10 * sizeof(int), 0);

    print_array(result_buffer, 10);

    

    return 0;
}

int main(int argc, char** argv) {

    create_client("127.0.0.1", 3000);
}