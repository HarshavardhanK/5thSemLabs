#include <stdio.h>

int main(int argc, char** argv) {
    int page_size;
    int total_mem;

    int offset, page_num;

    printf("Enter page size: "); scanf("%d", &page_size);
    printf("Enter byte mem: "); scanf("%d", &total_mem);

    offset = total_mem % page_size;
    page_num = total_mem / page_size;

    printf("Page number %d | Offset %d\n", page_num, offset);

    return 0;
}