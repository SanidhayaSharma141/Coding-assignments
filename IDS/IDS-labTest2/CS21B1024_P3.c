//Name; Sanidhaya Sharma (CS21B1024)
// CS21B1024_P3.C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node //queue struct declared that will be used for reversing a line
{
    int data; 
    struct Node *next;
};
typedef struct Node node;
node *front=NULL;
node *rear=NULL;

void enqueue(int data){
    node* addptr=malloc(sizeof(node));//declared node that will store the data
    addptr->data=data;
    addptr->next=NULL;
    if((front==NULL)&&(rear==NULL)){//empty stack condition
        front=addptr;
        rear=addptr;
    }
    else{
        rear->next=addptr;
        rear=rear->next;//now top will point to the newly added node
    }
}
int dequeue(){
    node* fr=front;
    if(front==NULL){//empty queue condition
        return 0;
    }
    else{
        int x=front->data;
        front=front->next;
        if(front==NULL){
            rear=NULL;
        }

        free(fr);
        return(x);
    }
}
void linereverse(char str[])//this fxn will reverse the string
{
    for (int i = 0;strlen(str)>i;i++)
    {
        enqueue(str[i]);
    }
    for(int i=strlen(str)-1;(front!=NULL)&&(strlen(str)>i);i--)
    {
        str[i] = dequeue();
    }
    for (int i = 0;strlen(str)>i;i++)
    {
        printf("%c", str[i]);
    }

}


int main(void)
{
    char strline[300];
    fgets(strline,300,stdin);
    linereverse(strline);

}