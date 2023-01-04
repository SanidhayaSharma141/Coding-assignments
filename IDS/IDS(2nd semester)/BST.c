#include <stdio.h>
#include <stdlib.h> //included lib
#include <math.h>

struct Node // initialised a tree struct
{
    struct Node *left;
    int data;
    struct Node *right;
};

typedef struct Node node;
node *root = NULL; //root will always point to top element(root of tree)
node *ptr = NULL;

node *create(int data)//creating a node
{
    node *temp = malloc(sizeof(node *));
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
node *insert(node *ptr, int data)//insertion operation while considering various conditions in order to be inserted in a sorted way
{
    node *tempp = malloc(sizeof(node *));
    if (root == NULL)
    {
        root = create(data);
    }
    else if (ptr == NULL)
    {
        ptr = create(data);

        return ptr;
    }
    else if (ptr->data > data)//if data is less then the ptr data, insertion will be at left
    {
        tempp = insert(ptr->left, data);
        ptr->left = tempp;
    }
    else if (ptr->data < data)//if data is bigger then the ptr data, insertion will be at right
    {
        tempp = insert(ptr->right, data);
        ptr->right = tempp;
    }
}

void search(node *temp, int data, int x)
{
    if (root == NULL)//empty tree condition
    {
        printf("%d not found, empty tree\n", data);
    }
    else if (temp == NULL)//ptr is null that means after completion of binary search, we couldnot find the searched element
    {
        printf("%d not found, last node on path: %d\n", data, x);
    }
    else if (temp->data == data)//data found if it matches
    {
        printf("found %d !\n", data);
    }
    else if (temp->data > data)//left condition
    {
        search(temp->left, data, temp->data);
    }
    else if (temp->data < data)//right condition
    {
        search(temp->right, data, temp->data);
    }
}
void deallocateheap(node* node)
{
    if (node == NULL) return;

    deallocateheap(node->left);
    deallocateheap(node->right);

    free(node);
}
// node* searchdel(node *temp,int data){
//     if(root==NULL){

//     }
//     else if(temp==NULL){
//         printf("%d not found",data);
//     }
//     else if(temp->right->data==data){
//         return temp;
//     }
//     else if(temp->left->data==data){
//         return temp;
//     }
//     else if(temp->data>data){
//         searchdel(temp->left,data);
//     }
//     else if(temp->data<data){
//         searchdel(temp->right,data);
//     }
// }

node *minnode(node *val)//this will be used when node with two child would be deleted to min from below would be needed to replace it
{
  node *temp = val;

  while (temp->left != NULL)
    temp = temp->left;

  return temp;
}
void printPreorder(node* node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    printf("%d ", node->data);

    /* then recur on left subtree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}
//Ques Part  ----Deleting node(Balanced way)------
node *Delete(node *root, int data,int c)
// !!!!!note the reason behind int c!!!!
//c will make sure that is node with two child is deleted,the line for deletion of minimum i.e 
// if node 4 is deleted which has two childs the min node that will be replacing it needs to be deleted due to which that line"__ 
// deleted is also shown so this will not let that happen
{
  // deletion will be done by BST algorithm only but the sorting/balancing will be done after deletion
  if (root == NULL)
  {
    printf("%d not found\n", data);
    return NULL;
  }

  else if (data < root->data) // searching at left if smaller than node
    root->left = Delete(root->left, data,c);

  else if (data > root->data) // searching at right if larger than node
    root->right = Delete(root->right, data,c);

  else
  {
    if ((root->left != NULL) && (root->right != NULL))
    {
      node *temp = minnode(root->right);
      if(c!=0)
      {printf("%d deleted\n", data);
      }
      root->data = temp->data;

      root->right = Delete(root->right, temp->data,0);
    }
    else{
      //if node has two Children i.e left and right both are not NULL
     // if the node has only one child or no child(leaf condition)
      // if(root->left==NULL&&root->right==NULL){
      //   temp==NULL;
      // }
      node*temp;
      if(root->left==NULL){
        temp=root->right;
      }
      else{
        temp=root->left;
      }

      if (temp == NULL)//if both are null
      {
        temp = root;
        root = NULL;
      }
      else
      {
        *root = *temp;
      }
      free(temp);
      if(c!=0){
      printf("%d deleted\n", data);}
    }

  }
  return root;
}



int main(void)
{
    char func = 0;
    int data;
    node *value;
    while (func != 'x')
    {                       //'x' will end the program
        scanf("%c", &func); // fxns to be called on the basis of whats input is given
        if (func == 'i')
        {
            scanf("%d", &data);             // element to be pushed in stack taken as input
            node *tmp = insert(root, data); // calling function
        }
        else if (func == 'd')
        {
            scanf("%d", &data);
            value = Delete (root, data,1); // calling function
        }
        else if (func == 's')
        {
            scanf("%d", &data);
            search(root, data, 0);
        }
        else if (func == 'b')
        {
            printPreorder(root);
        }
        fflush(stdin);
    }
    deallocateheap(root);
    printf("%d",root->data);
    return 0;
}