#include <stdio.h>
#include <stdlib.h>

#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

int create_server(char* ip, unsigned short int port) {

    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in server_addr;
   
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    int _bind_ = bind(sock_fd, (struct sockaddr*) &server_addr, sizeof(server_addr));

    if(_bind_ == -1) {
        return -1;
    }

    return sock_fd;
}

int perform_task(int sock_fd, unsigned short int port) {

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(port);
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int *mat = (int*) malloc(sizeof(int) * 4);

    for(int i = 0; i < 2; i++) {

        int *arr = (int*) malloc(sizeof(int) * 2);

        printf("Receving %d row: \n", i);
        int _recv_ = recvfrom(sock_fd, arr, sizeof(arr), 0, (struct sockaddr*) &client_addr, &client_len);

        
        for(int j = 0; j < 2; j++) {
            mat[i * 2 + j] = arr[j];
            printf("%d ", mat[i * 2 + j]);
        }

        printf("\n");
            

    }

    printf("\nresult\n");

    for(int i = 0; i < 2; i++) {

        for(int j = 0; j < 2; j++)
            printf("%d ", mat[i * 2 + j]);
        
        printf("\n");
    }

    int _send_ = sendto(sock_fd, mat, sizeof(mat), 0, (struct sockaddr*) &client_addr, client_len);

    return 0;
        

}

int main() {

    int sock_fd = create_server("127.0.0.1", 3000);

    perform_task(sock_fd, 3000);

    return 0;

    
}