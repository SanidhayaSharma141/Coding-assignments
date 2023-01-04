// <CS21B1024> <SANIDHAYA SHARMA>
//<CS21B1024_P2.c>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node 
{
    int data; 
    struct Node *next;
};
typedef struct Node node;
node *head1;
node * head2;
//you can uncomment them to check its functioning
// void insertll(int n) //insertion fxn made to add nodes
// {
//     node *temp =(node*)malloc(sizeof(node)); //used dynamic allocation
//     temp->data=n; 
//     temp->next=NULL;
//     if (head1==NULL)
//     {
//         head1=temp;
//     }
//     else{
//         node *tempp=head1;
//         for(;tempp->next!=NULL;) {
//             tempp=tempp->next;
//         }
//         tempp->next=temp;
//     }
// }
// void insert(int n) //insertion fxn made to add nodes
// {
//     node *temp =(node*)malloc(sizeof(node)); //used dynamic allocation
//     temp->data=n; 
//     temp->next=NULL;
//     if (head2==NULL)
//     {
//         head2=temp;
//     }
//     else{
//         node *tempp=head2;
//         for(;tempp->next!=NULL;) {
//             tempp=tempp->next;
//         }
//         tempp->next=temp;
//     }
// }





// NOTE!!-in question its written" all elements of head1 are inserted AFTER head2 in the same order as they were in head 1" meaning head1 comes after head2..therefore i did that wayyy!!
 
 
 
 
 
 
 void concat(node * head1,node*head2){
     node* temp=head2;
     if((head2==NULL)||(head1==NULL)){
         printf("nothing in head2 to concatenate");
     }
     else{
     while(temp->next!=NULL){
         temp=temp->next;
     }
     
     temp->next=head1;}
 }
//  void traverse(){//function for traversing the linked list

//     for(node*tempp=head2;tempp!=NULL;tempp=tempp->next)//untill it encounters null,the loop will keep traversing
//     printf("%d ",tempp->data);
// }
// int main(void){   
//     char func=0;
//     int data;
//     int value;
//     while (func!='x'){//'x' will end the program
//         scanf("%c",&func);//fxns to be called on the basis of whats input is given
//         if (func=='i'){
//             scanf("%d" ,&data);//element to be pushed in stack taken as input
//             insert(data);//calling function
//         }
//         if (func=='j'){
//             scanf("%d" ,&data);//element to be pushed in stack taken as input
//             insertll(data);//calling function
//         }
//         else if (func=='d'){
//             concat(head1,head2);
//         }
//         else if(func=='t'){
//             traverse();
//         }
//         fflush(stdin);
//     }
//     // while(head2!=NULL) dequeue();
//     return 0;
// }
