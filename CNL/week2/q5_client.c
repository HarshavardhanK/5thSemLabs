#include "client.h"

int receive_time(void* buffer, int buffer_size) {

    buffer = (char*) buffer;

    printf("Recevied time %s\n", buffer);

    return 1;
}

int main() {

    create_client("127.0.0.1", 3000, CHAR, NULL, 256, receive_time);
}