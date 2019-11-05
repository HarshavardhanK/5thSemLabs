#include "tree.h"

void test_binary_tree() {

    TNode* root = get_tree();
    
    inorder(root);
    printf("\n");

    if(search(root, 7) != NULL) {
        printf("7 found\n");

    } else {
        printf("not found\n");
    }
}

void test_avl_tree() {

    TNode* root = NULL;

    for(int i = 0; i < 10; i++) {
        root = avl_insert(root, i);
        //printf("Root is %d\n", root->data);

    }
    

    if(search(root, 8) != NULL) {
        printf("found\n");

    } else {
        printf("not found\n");
    }
}

int main() {
    //test_binary_tree();
    test_avl_tree();

    return 0;
}