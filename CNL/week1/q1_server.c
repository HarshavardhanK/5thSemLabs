#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <string.h>

int perform_server_task(int socket_fd, char* buffer) {

    struct sockaddr_in client_addr;
    int client_addr_l;

    int sockfd = accept(socket_fd, (struct sockaddr*)& client_addr, &client_addr_l);

    if(buffer && sockfd != -1) {

        int read_status = read(sockfd, buffer, sizeof(buffer));

        if(read_status != -1) {
            puts(buffer);
            return -1;
        }

        int write_status = write(sockfd, buffer, sizeof(buffer));

        if(write_status != -1) 
            printf("Sent message: %s", buffer);
    } 

    return 0;
}

int create_socket(char* ip_addr, unsigned short int port_no) {

    int socket_file_desc;
    int new_socket_file_desc;

    int client_addr_length;
    int write_status;
    
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

    printf("hello\n");

    while(1) {

        char buffer[512];
        puts("server waiting..");

        /*client_addr_length = sizeof(client_addr);

        new_socket_file_desc = accept(socket_file_desc, (struct sockaddr*)& client_addr, &client_addr_length);

         write_status = read(new_socket_file_desc, buffer, sizeof(buffer));

        puts(buffer);

        write_status = write(new_socket_file_desc, buffer, sizeof(buffer));**/

        if(perform_server_task(socket_file_desc, buffer) == 0)
            printf("Success\n");
        else
        {
            printf("Fail\n");
            return -1;
        }

    }

    return 0;
    
}

int main(int argc, char** argv) {

    if(create_socket("172.16.48.92", 10202) == 0) {
        printf("Communication success\n");

    } else {
        printf("Communication failed\n");
    }

}