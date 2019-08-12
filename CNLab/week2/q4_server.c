#include "server.h"

int generate_result(int* buffer, int size) {

    int x = buffer[0];
    int y = buffer[1];
    char op = buffer[2];
    buffer[3] = 0;

    if(op == 1)
        buffer[3] = x + y;

    else if(op == 2)
        buffer[3] = x - y;

    else if(op == 3)
        buffer[3] = x * y;

    else
        buffer[3] = x / y;
    
    printf("\nResult from server is: %d\n", buffer[3]);

    return 1;
}

int main(int argc, char** argv) {

    int server = create_server("127.0.0.1", 3000, 4, generate_result);

    return 0;
}