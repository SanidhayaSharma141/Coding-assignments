#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node 
{
    int data; 
    struct Node *next;
};
typedef struct Node node;
node *front=NULL;
node *rear=NULL;

void enqueue(int n) //insertion fxn made to add nodes
{
    node *temp =(node*)malloc(sizeof(node)); //used dynamic allocation
    temp->data=n; 
    temp->next=NULL;
    if ((rear==NULL)&&(front==NULL))
    {
        front=temp;
        rear=temp;
        rear->next=front;
    }
    else{
        rear->next=temp;
        temp->next=front;
        rear=temp;
    }
}
void dequeue(){//function for delete the given node from the linked list
    if ((rear==NULL))
    {
        printf("queue underflow");
    }
    else if(front==rear){
        front=rear=NULL;
    }
    else{

    node* temp=front;
    front=front->next;
    rear->next=front;
    free(temp);
    }
}
void print(){
    if((front==NULL)&&(rear==NULL)){
        printf("queue empty");
        }
    else{
            node*temp=front;
            do{
                printf("%d ",temp->data);
                temp=temp->next;
            }while(temp!=front);
            printf("\n");
        }

}
int main(void){   
    char func=0;
    int data;
    int value;
    while (func!='x'){//'x' will end the program
        scanf("%c",&func);//fxns to be called on the basis of whats input is given
        if (func=='e'){
            scanf("%d" ,&data);
            enqueue(data);
        }
        else if (func=='d'){
           dequeue();//calling function

        }
        else if(func=='t'){
            print();
        }
        fflush(stdin);
    }
    while(front!=NULL) dequeue();
    return 0;
}