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
node *end=NULL;

void enqueue(int data){
    node* ptr=malloc(sizeof(node));//declared node that will store the data
    ptr->data=data;
    ptr->next=NULL;
    if((front==NULL)&&(end==NULL)){//empty stack condition
        front=ptr;
        end=ptr;
    }
    else{
        end->next=ptr;
        end=end->next;//now top will point to the newly added node
    }
}
// note: use this to see changesin queue
void print(){
    if((front==NULL)&&(end==NULL)){
        printf("queue empty");
    }
    else{
        printf(" front: %d\n",front->data);
         printf(" end: %d\n",end->data);
   for(node* tempp=front;tempp!=NULL;tempp=tempp->next){
       printf("%d ",tempp->data );
   }
   printf("\n");}
}

int dequeue(){
    node* temp=front;
    if(front==NULL){//empty stack condition
        printf("empty queue\n");
        return -1;
    }
    else{
        // printf("%d",top->data);
        int x=front->data;
        front=front->next;
        if(front==NULL){
            end=NULL;
        }

        free(temp);
        return(x);
    }
}

int main(void){   
    char func=0;
    int data;
    while (func!='x'){//'x' will end the program
        scanf("%c",&func);//fxns to be called on the basis of whats input is given
        if (func=='P'){
            scanf("%d" ,&data);//element to be pushed in stack taken as input
            enqueue(data);//calling function
        }
        else if (func=='d'){
            dequeue();//calling function
            printf("\n");
        }
        else if(func=='t'){
            print();
        }
       
        fflush(stdin);
    }
    while(front!=NULL) dequeue();
    return 0;
}