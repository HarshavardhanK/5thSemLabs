#include <stdio.h>
#include <stdlib.h>

int compare(const void* A, const void* B) {
    return ((int*)B) - ((int*)A);
}

void make_change(unsigned int change_, int denominations[], int result[], int size) {

    qsort((void*)denominations, size, sizeof(int), compare);
   
    for(int i = 0; i < size; i++)
        result[i] = 0;

    for(int i = 0; i < denominations[size - 1]; i++) {
        result[i] = 0;
    }

    int d = 0;

    while(change_ > 0 && d < size) {

        int diff = change_ - denominations[d];

        if(diff >= 0) {
            change_ = diff;
            result[d]++;

        } else {
            d++;
        } 

    }

}

int main(int argc, char** argv) {

    if(argc < 3) {
        printf("Format for input is \"$./change [denomation_length] [change]\"\n");
        return 1;
    }

    int size = atoi(argv[1]);
    int change = atoi(argv[2]);

    int result[size];
    int denomination[size];

    printf("Enter change denomination\n");

    for(int i = 0; i < size; i++) {
        scanf("%d", &denomination[i]);
    }

    make_change(change, denomination, result, size);

    printf("Denominations are\n");

    for(int i = 0; i < size; i++) {
        printf("%d of Rs %d\n", result[i], denomination[i]);
    }

    return 0;
}