#include <stdio.h>
#include <stdlib.h>

void print_list(void* list, int size) {

    char *p_arr = list;

    for(int i = 0; i < size; i++)
        printf("%c ", p_arr[i]);

}

int main(int argc, char** argv) {
    char *arr = (char*) malloc(sizeof(char) * 3);

    for(int i = 0; i < 3; i++)
        scanf(" %c", &arr[i]);
    
    print_list(&arr, 3);

    arr = (void*) arr;

    return 0;
}