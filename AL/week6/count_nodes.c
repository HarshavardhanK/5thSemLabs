#include "binary_tree.h"

#include <fcntl.h>

#include <time.h>

double time_taken(void (*function) (int), int size) {

    clock_t timer;
    timer = clock();

    function(size);

    timer = clock() - timer;

    return ((double) timer) / CLOCKS_PER_SEC;
}

void count(Node* root, int *c) {

    
    if(root) {
        count(root->left, c);
        (*c)++;
        count(root->right, c);
    }

}

void run(int size) {

    Node* root = NULL;
    int c = 0;

    for(int i = 10000; i < size; i += 10000) {
        bst_insert(&root, rand() % (i * 13 + 11));
    }

    count(root, &c);
}

int main() {

   FILE* res = fopen("count_res.csv", "w");

   for(int i = 10000; i < 1000000; i += 10000) {
       double time = time_taken(run, i);
       fprintf(res, "%d, %.6f\n", i, time);
   }

   fclose(res);

    return 0;
}