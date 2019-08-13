
#ifndef SERVER_H
#define SERVER_H

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <string.h>


int create_socket(char* ip_addr, unsigned short int port_no, int (*server_task)(int, char*)) {

    int socket_file_desc;
    int new_socket_file_desc;

    socklen_t client_addr_length;
    socklen_t write_status;
    
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;

    socket_file_desc = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;

    if(ip_addr != NULL) {

        server_addr.sin_addr.s_addr = inet_addr(ip_addr);
        server_addr.sin_port = htons(port_no);

        printf("IP address is: %s || PORT NO: %d\n", ip_addr, port_no);
        

    } else {
        printf("ip address is not valid\n");
        return -1;
    }
        
    int bind_status = bind(socket_file_desc, (struct sockaddr*)& server_addr, sizeof(server_addr));
    int listent_status = listen(socket_file_desc, 5);

    while(1) {

        char buffer[512];
        puts("server waiting..");
        
        int _server_task_ = server_task(socket_file_desc, buffer);

        if(_server_task_ != 0) {

            printf("\nserver task %d\n", _server_task_);
            printf("Success\n");

        } else {

            printf("\nserver task %d\n", _server_task_);
            printf("Fail\n");
            
        }

    }

    return 0;
    
}

#endif