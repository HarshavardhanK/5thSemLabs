#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {return a > b ? a : b;}

struct node {

    struct node* left;
    struct node* right;
    int height;
    int data;
};

typedef struct node Node;

Node* init_node(int data) {
    
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->height = 1;

    node->left = NULL;
    node->right = NULL;

    return node;
}

int height(Node* root) {

    if(root) {

        int left_height = height(root->left);
        int right_height = height(root->right);

        return 1 + max(left_height, right_height);
    }

    return 0;

}

void bst_insert(Node** root, int data) {

    if(*root == NULL) {
        *root = init_node(data);

    } else {

        if(data < (*root)->data)
            bst_insert(&(*root)->left, data);
        
        else
            bst_insert(&(*root)->right, data);
    }
}

Node* right_rotate(Node* node) {

    Node* tmp = node->left;
    Node* tmp2 = tmp->right;

    tmp->right = node;
    node->left = tmp2;

    node->height = 1 + max(height(node->left), height(node->right));
    tmp->height = 1 + max(height(tmp->left), height(tmp->right));

    return tmp;

}

Node* left_rotate(Node* node) {

    Node* tmp = node->right;
    Node* tmp2 = tmp->left;

    tmp->left = node;
    node->right = tmp2;

    node->height = 1 + max(height(node->left), height(node->right));
    tmp->height = 1 + max(height(tmp->left), height(tmp->right));

    return tmp;

}

int balance(Node* node) {

    if(node) {
        return height(node->left) - height(node->right);
    }

    return 0;
}


void print_inorder(Node* root) {

    if(root) {

        print_inorder(root->left);
        printf("%d ", root->data);
        print_inorder(root->right);
    }
}



int num_nodes(Node* root) {

    int count = 1;

   if(root->left) {
       count += num_nodes(root->left);
    }

    if(root->right != NULL) {
        count += num_nodes(root->right);
    }

    return count;
}

void balance_factor(Node* root) {
    
    if(root) {

        balance_factor(root->left);

        int right_height = height(root->right);
        int left_height = height(root->left);

        int blnce = left_height - right_height;

        printf("blnce factor for %d node is %d\n", root->data, blnce);

    
        balance_factor(root->right);

        
    }
   
}

void avl_insert(Node** root, int data) {

    if(*root == NULL) {
        *root = init_node(data);

    } else {

        Node* iter = *root;
        Node* aux = *root;

        while(iter != NULL) {

            aux = iter;

            if(data > iter->data)
                iter = iter->right;

            else if(data < iter->data)
                iter = iter->left;
            
            else
                return; //no duplicato
            
        }

        if(data > aux->data)
            aux->right = init_node(data);
        else
            aux->left = init_node(data);
        
        aux->height = 1 + max(height(aux->left), height(aux->right));

        int blnce = balance(aux);

        if(blnce > 1 && data < aux->left->data)
            right_rotate(aux);
        
        if(blnce < -1 && data > aux->right->data)
            left_rotate(aux);
        
        if(blnce > 1 && data > aux->left->data) {
            aux->left = left_rotate(aux);
            right_rotate(aux);
        }

        if(blnce < -1 && data < aux->right->data) {
            aux->right = right_rotate(aux);
            left_rotate(aux);
        }

    }

}


Node* avl__insert(Node* node, int data) {  
    
    if (node == NULL)  
        return(init_node(data));
  
    if (data < node->data)  
        node->left = avl__insert(node->left, data);  

    else if (data > node->data)  
        node->right = avl__insert(node->right, data);  

    else 
        return node;  
  
   
    node->height = 1 + max(height(node->left), height(node->right));  
  
    int blnce = balance(node);  
  
    if (blnce > 1 && data < node->left->data)  
        return right_rotate(node);  
  
    if (blnce < -1 && data > node->right->data)  
        return left_rotate(node);  
  
    if (blnce > 1 && data > node->left->data) {  
        node->left = left_rotate(node->left);  
        return right_rotate(node);  
    }  
  
    if (blnce < -1 && data < node->right->data) {  
        node->right = right_rotate(node->right);  
        return left_rotate(node);  
    }  
  
   
    return node;  
}  



#endif

