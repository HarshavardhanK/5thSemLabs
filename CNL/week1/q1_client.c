#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#include "client.h"


int perform_client_task(int sockfd, char* buffer, int *value) {

    *value = read(sockfd, buffer, sizeof(buffer));
    printf("\nMessage from server is %s\n", buffer);

    return 1;

}


int main(int argc, char** argv) {

    create_client("127.0.0.1", 3000, 1, perform_client_task);
}