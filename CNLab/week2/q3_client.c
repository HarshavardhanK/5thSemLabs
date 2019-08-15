#include "client.h"

int print_array(int* arr, int size) {

    printf("\n");

    for(int i = 0; i < size; i++)
        printf("%d ", ((int*)arr)[i]);

    printf("\n");

    return 1;
}

int main(int argc, char** argv) {

    int arr[10] = {4,5,6,-1,1,2,8,7,3,6};

    int client = create_client("127.0.0.1", 3000, INT, arr, 10, print_array);

    return 0;
}