#include "binary_tree.h"

int diameter(Node* root) {

    if(root) {

        int left_l = height(root->left);
        int right_h = height(root->right);

        return 1 + left_l + right_h;
    }

    return 0;
}

int main() {

    Node* root = NULL;

    for(int i = 1; i < 6; i++)
        bst_insert(&root, rand() % (i * 13 + 31));
    
    int dim = diameter(root);

    printf("Diameter is %d\n", dim);

    return 0;
}