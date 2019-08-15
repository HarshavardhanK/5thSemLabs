
#include "client.h"

int read_time(int* buffer, int buffer_size) {

    buffer = (char*) buffer;

    printf("\nServer time is %s\n", buffer);

    return 1;
}

int main(int argc, char** argv) {

    int client = create_client("127.0.0.1", 3000, NULL, 0, 0, read_time);

    if(client != -1) {
        printf("Successfully read time\n");
    }

    return 0;
}

