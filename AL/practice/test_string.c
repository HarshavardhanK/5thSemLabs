#include "string_manip.h"

void test_naive_search() {
    char* string = "Mountbatten"; char* pattern = "bat";

    if(string_search_naive(string, pattern)) {
        printf("%s found\n", pattern);

    } else {
        printf("%s not found\n", pattern);
    }
}

void test_boyer_moore() {

    char* string = "Mountbatten has a bat which is weirds o weird vert weird"; char* pattern = "bat";

    printf("%d\n", string_search_boyer_moore(string, pattern));

    printf("Len: %d\n", strlen(string));

}

int main() {
    test_boyer_moore();
}