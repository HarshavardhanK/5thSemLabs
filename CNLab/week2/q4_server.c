#include "server.h"

int generate_result(void* buffer, int size) {

    if(buffer == NULL) {
        printf("\nBuffer is empty\n");
        return -1;
    }

    int x = ((int*)buffer)[0];
    int y = ((int*)buffer)[1];
    int op = ((int*)buffer)[2];
    ((int*)buffer)[3] = 0;

    print_buffer(buffer, 4);

    if(op == 1)
        ((int*)buffer)[3] = x + y;

    else if(op == 2)
        ((int*)buffer)[3] = x - y;

    else if(op == 3)
        ((int*)buffer)[3] = x * y;

    else
        ((int*)buffer)[3] = x / y;
    
    printf("\nResult from server is: %d\n", ((int*)buffer)[3]);

    return 1;
}

int main(int argc, char** argv) {

    int server = create_server("127.0.0.1", 3000, 4, INT, generate_result);

    return 0;
}