#include "client.h"

void generate_input_buffer(int* buffer) {

    int x, y;
    char op;

    printf("Enter x: \n"); scanf("%d", &x);
    printf("Enter y: \n"); scanf("%d", &y);
    printf("Enter operand: \n"); scanf(" %c", &op);

    printf("%c\n", op);

    buffer[0] = x; buffer[1] = y;
    buffer[3] = 0;

    if(op == '+') {
        buffer[2] = 1;
        printf("\n adding \n");

    } else if(op == '-') {
        buffer[2] = 2;

    } else if(op == '*') {
        buffer[2] = 3;

    } else {

        buffer[2] = 3;
        printf("Considering division\n");

        if(y == 0) {
            printf("invalid. restart program\n");
            exit(0);
        }

    }
    
}

int generate_output(int* buffer, int size) {

    printf("\nResult is %d\n", buffer[3]);

    return 0;
}

int main(int argc, char** argv) {

    int* input = (int*) malloc(sizeof(int) * 4);
    generate_input_buffer(input);

    int client = create_client("127.0.0.1", 3000, &input, 4, generate_output);

    return 0;


}