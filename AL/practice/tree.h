#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

struct tree_node {
    int data;
    
    struct tree_node* right;
    struct tree_node* left;

    int height;
};

typedef struct tree_node TNode;

TNode* create_tree_node(int data) {

    TNode* node = (TNode*) malloc(sizeof(TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    node->height = 1;

    return node;
}

void tree_insert(TNode* root, int data) {

    TNode* node = create_tree_node(data);

    if(!root) {
        root = node;

    } else {

        TNode* iter = root;
        TNode* aux = iter;

        while(iter != NULL) {
            aux = iter;

            if(data > iter->data) 
                iter = iter->right;
            else
                iter = iter->left;

        }

        if(data > aux->data)
            aux->right = node;
        else
            aux->left = node;

    }
}

int get_height(TNode* node) {

    if(node) {
        return node->height;
    }

    return 0;
}

TNode* right_rotate(TNode* y) {

    printf("right rotate\n");

    TNode* x = y->left;
    TNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(get_height(y->right), get_height(y->left)) + 1;
    x->height = max(get_height(x->right), get_height(x->left)) + 1;

    return x; // x is root
}

TNode* left_rotate(TNode* x) {

    printf("Left rotate\n");

    TNode* y = x->right;
    TNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(get_height(y->right), get_height(y->left)) + 1;
    x->height = max(get_height(x->right), get_height(x->left)) + 1;

    return y; //y is root

}

#define INVALID_NODE 1000

int balance_factor(TNode* node) {

    if(node) {
        return get_height(node->left) - get_height(node->right);

    } else {
        printf("Invalid node\n");
        return 0;
    }
}

TNode* avl_insert(TNode* root, int data) {

   // printf("Insert method\n");

    TNode* node = create_tree_node(data);

    if(root == NULL) {
        return create_tree_node(data);

    } else {

      //  printf("inserting %d at %d\n", data, root->data);

        if(data > root->data)
            root->right = avl_insert(root->right, data);

        else if(data < root->data)
            root->left = avl_insert(root->left, data);
        
        else
            return root;

        root->height = max(get_height(root->right), get_height(root->left)) + 1;

        int balance = balance_factor(root);
        //printf("Balance factor: %d\n", balance);

        //if left tree has greater height
        if(balance > 1 && data < root->left->data)
            return right_rotate(root);
        
        //if right tree has greater height
        if(balance < -1 && data > root->right->data)
            return left_rotate(root);

        if(balance > 1 && data > root->left->data) {
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }

        if(balance < -1 && data < root->right->data) {
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }
    }

    return root;

}

TNode* search(TNode* root, int data) {

    int count = 0;

    if(root) {

        TNode* iter = root;

        while(iter != NULL) {
            count++;

            if(data > iter->data) 
                iter = iter->right;

            else if(data < iter->data)
                iter = iter->left;

            else if(data == iter->data) {
                printf("Travelled %d count nodes\n", count);
                return iter;
            }
                
        }
    }

    return NULL;
}

void inorder(TNode* root) {

    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

//Generate trees
TNode* generate_tree(int capacity) {

    TNode* root = create_tree_node(9);

    for(int i = 1; i <= capacity; i++) {
        int data = rand() % 31;
        printf("Inserting: %d\n", data);
        tree_insert(root, data);
    }

    return root;
}

TNode* get_tree() {

    TNode* root = create_tree_node(10);
    tree_insert(root, 4);
    tree_insert(root, 14);
    tree_insert(root, 23);
    tree_insert(root, 16);
    tree_insert(root, 8);
    tree_insert(root, 11);
    tree_insert(root, 31);
    tree_insert(root, 29);
    tree_insert(root, 18);
    tree_insert(root, 3);
    tree_insert(root, 0);
    tree_insert(root, 9);
    tree_insert(root, 6);
    tree_insert(root, 7);

    return root;
}

TNode* get_avl_tree() {

    TNode* root = NULL;

    root = avl_insert(root, 10);
    root = avl_insert(root, 4);
    root = avl_insert(root, 14);
    root = avl_insert(root, 23);
    root = avl_insert(root, 16);
    root = avl_insert(root, 8);
    root = avl_insert(root, 11);
    root = avl_insert(root, 31);
    root = avl_insert(root, 29);
    root = avl_insert(root, 18);
    root = avl_insert(root, 3);
    root = avl_insert(root, 0);
    root = avl_insert(root, 9);
    root = avl_insert(root, 6);
    root = avl_insert(root, 7);

    return root;

}

#endif