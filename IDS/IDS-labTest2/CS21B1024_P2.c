//Name; Sanidhaya Sharma (CS21B1024)
// CS21B1024_P2.C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Node //created a struct for linked list
{
    int data; 
    struct Node *next;
};
typedef struct Node node;
node *top=NULL;//initialised top..in our stack using linked list...head will act as top and node at beginning will act as top

//insert fxn
void insert(int data){//it is similar to stack as insertion occurs at end
    node* ptr=malloc(sizeof(node));//declared node that will store the data
    ptr->data=data;
    if(top==NULL){//empty stack condition
        ptr->next=NULL;
        top=ptr;
    }
    else{
        ptr->next=top;
        top=ptr;//now top will point to the newly added node
    }
}
//pop fxn
int pop(){
    int dat;
    node* temp=top;
    if(top==NULL){//empty stack condition
        return 0;
    }
    else{
        dat=top->data;
        top=top->next;
        free(temp);
    }
    return dat;
}

// void print(){
//     if(top==NULL){
//         printf("stack underflow");
//     }
//     else{
//    for(node* tempp=top;tempp!=NULL;tempp=tempp->next){
//        printf("%d ",tempp->data );
//    }
//    printf("\n");}
// }
int sumandavg(node * top){
    int x;
    int sum=0;
    int count=0;
    float avg;
    for(node *temp=top;temp!=NULL;temp=temp->next){
        sum=sum+temp->data;
        count++;
    }
    avg=sum/(count);
    printf("%d %f",sum,avg);
    return 0;
}

int main(void){   
    srand((0));
    int s,a,x;
    for(int i=0;i<(27*(24/2));i++){//as my roll no. is 24
        x=(rand()%120)-20;//in order to give specific range i had to do this
        insert(x);
        x=(rand()%120)-150;
        insert(x);
    }
   
    sumandavg(top);
    
    return 0;
}

