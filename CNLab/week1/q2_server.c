#include <time.h>
#include <string.h>

#include "server.h"

int perform_server_task(int socket_fd, char* buffer) {

    struct sockaddr_in client_addr;
    socklen_t client_addr_l;

    int sockfd = accept(socket_fd, (struct sockaddr*)& client_addr, &client_addr_l);

    time_t rawtime;
    struct tm *info;
    time( &rawtime );
    info = localtime( &rawtime );

    strcpy(buffer, asctime(info));

    printf("Time is %s\n", buffer);

    int write_status = write(socket_fd, buffer, sizeof(char) * 512);

    if(write_status != -1) {
        printf("error in writing status %d\n", write_status);
        return 0;

    } else {
        printf("\nSuccessfully written to client\n");
    }

    return 1;

}

int main(int argc, char** argv) {

    int server = create_socket("127.0.0.1", 3000, perform_server_task);

    if(server) {
        printf("Successfully sent time\n");

    } else {
        printf("Server task failed");
    }

    return 0;
}