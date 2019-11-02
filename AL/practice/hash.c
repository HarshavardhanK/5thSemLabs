#include "hash.h"

void manual() {

    Hash* table = init_hash(5);

    printf("Enter num string: ");
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        char val[20];
        scanf("%s", val);

        hash(table, val);

        //hash(table, val);
    }

    printf("\nHash table is\n");

    print_hash_table(table);

   char* str = (char*) malloc(sizeof(char) * 20);

    printf("Enter string to seach: ");
    scanf("%s", str);

    int search_val = search(table, str);

    if(search_val) {
        printf("Found at %d\n", search_val); 
    } else {
        printf("Not found\n");
    }

}

int main(int argc, char** argv) {

    manual();
    

    return 0;
}