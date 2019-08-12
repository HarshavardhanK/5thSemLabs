#include "client.h"

int print_array(int* arr, int size) {

    printf("\n");

    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 1;
}

int main(int argc, char** argv) {

    int arr[] = {4,5,6,3,2,1,6,7,8,-1};

    int client = create_client("127.0.0.1", 3000, &arr, 10, print_array);

    return 0;
}