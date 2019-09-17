#include "binary_tree.h"

void test_bst() {

    Node* root = init_node(10);

    for(int i = 0; i < 9; i++) {
        int ins = rand() % (i + 4);
        printf("Inserting %d\n", ins);
        bst_insert(&root, ins);
    }

    print_inorder(root);

    printf("\nHeight of tree is %d\n", height(root));

    printf("Num nodes %d\n", num_nodes(root));

    balance_factor(root);

}

void test_avl() {

    Node* root = init_node(10);

    for(int i = 0; i < 9; i++) {
        int ins = rand() % (i + 4);
        printf("Inserting %d\n", ins);
        root = insert(root, ins);
    }

    print_inorder(root);

    printf("\nHeight of tree is %d\n", height(root));

}

int main(int argc, char** argv) {

    //test_bst();
    test_avl();

    return 0;
}