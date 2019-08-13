
#include "client.h"

int read_time(int sockfd, char* buffer, int *read_status) {

    *read_status = read(sockfd, buffer, sizeof(char) * 512);
    puts(buffer);

    if(*read_status != -1) {

        printf("Successfully read time\n");
        
        printf('\n');

        return 1;

    } else {
        printf("error in reading time\n");
        return 0;
    }
}

int main(int argc, char** argv) {

    int client = create_client("127.0.0.1", 3000, read_time, 0);

    if(client != -1) {
        printf("Successfully read time\n");
    }

    return 0;
}

