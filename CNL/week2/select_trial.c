#include <sys/types.h>
#include <sys/socket.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netinet/in.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <unistd.h>

void print_array(int arr[], int size) {

    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 

    for (i = 0; i < n-1; i++) 
    { 
         
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        swap(&arr[min_idx], &arr[i]); 
    } 
} 

int main(int argc, char** argv) {
    
    int server_sockfd, client_sockfd;
    int server_len, client_len;

    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    int result;

    fd_set readfds, test_fds;

    //
    int buffer[10];

    //Create and name a socket for the server
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;

    server_address.sin_addr.s_addr = inet_addr("172.16.48.92");

    server_address.sin_port = htons(10203);
    server_len = sizeof(server_address);

    bind(server_sockfd, (struct sockaddr*) &server_address, server_len);

    //create a connection queue and initialize readfds from server_sockfd
    listen(server_sockfd, 5);
    FD_ZERO(&readfds);
    FD_SET(server_sockfd, &readfds);

    while(1) {
        
        char ch;
        int fd, nread;

        test_fds = readfds;

        printf("Server waiting...");
        printf("\n");

        result = select(FD_SETSIZE, &test_fds, (fd_set*) 0, (fd_set*) 0, (struct timeval*) 0);

        printf("Hello\n");

        if(result < 1) {
            perror("server error");
            exit(1);
        }

        printf("\n");

        printf("FD_SETSIZE %d\n", FD_SETSIZE);

        for(fd = 0; fd < FD_SETSIZE; fd++) {

            if(FD_ISSET(fd, &test_fds)) {

                char client__sockfd[5];

                if(fd == server_sockfd) {

                    client_len = sizeof(client_address);
                    client_sockfd = accept(server_sockfd, (struct sockaddr* ) & client_address, &client_len);

                    FD_SET(client_sockfd, &readfds);
                    printf("adding client on fd %d\n", client_sockfd);
                    
                } else {

                    ioctl(fd, FIONREAD, &nread);

                    if(nread == 0) {

                        close(fd);
                        FD_CLR(fd, &readfds);
                        printf("removing client on fd%d\n", fd);

                    } else {

                        read(fd, buffer, sizeof(buffer));
                        //printf("%c\n", ch);
                        print_array(buffer, 10);
                        printf("\n");
                        
                        printf("serving client on fd%d\n", fd);

                        ch++;

                        selectionSort(buffer, 10);
                        print_array(buffer, 10);

                        write(fd, buffer, 10);
                        //write(fd, getpid(), sizeof(int));
                    }
                }
            }
        }
    }
}
