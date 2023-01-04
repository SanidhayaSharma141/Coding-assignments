//Name; Sanidhaya Sharma (CS21B1024)
// CS21B1024_P1.C

#include <stdio.h>
#include <stdlib.h>

//declared struct for avl tree
//wrote this as the code shows error if not written as they ll be undefined
struct Node
{
  int key;
  struct Node *left;
  struct Node *right;
  int height; // this will be used inorder to access a node's height for sorting purpose/bal
};
typedef struct Node node;
node *root = NULL;




node* AVLTreeSearch(node* node,int key)
{
    if(root==NULL){
        return root;
    }
    if (node == NULL){
        return root;}

    else if(node->key==key){
        return node;
    }
    else if(node->key>key){
    AVLTreeSearch(node->left,key);
    }
    else if(node->key<key){
    AVLTreeSearch(node->right,key);
    }
}




