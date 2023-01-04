// <CS21B1024> <SANIDHAYA SHARMA>
//<CS21B1024_P1.c>
//i was facing issue while making character queue thats why i made int queue

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node 
{
    int data; 
    int priority;
    struct Node *next;
};
typedef struct Node node;
node *front=NULL;
node *end =NULL;

void enqueue(int data,int priority){
    node* ptr=malloc(sizeof(node));//declared node that will store the data
    ptr->data=data;
    ptr->priority=priority;
    if((front==NULL)){//empty stack condition
        ptr->next=NULL;
        front=ptr;
        end=ptr;
    }
    else if((front->priority)<priority){
        ptr->next=front;
        front=ptr;
    }
    else if(end->priority>priority){
        end->next=ptr;
        ptr->priority=priority;
        ptr->next=NULL;
        end=ptr;

    }
    else{
        node* temp=front;
        while((temp!=NULL)&&(temp->next->priority>priority)){
            temp=temp->next;
        }
        ptr->next=temp->next;
        temp->next=ptr;
    }
}
int dequeue(){
    node* temp=front;
    if(front==NULL){//empty stack condition
        printf("empty queue\n");
        return -1;
    }
    else{
        int x=front->data;
        front=front->next;

        free(temp);
        return(x);
    }
}
// note: use this to see changesin queue
void print(){
    if((front==NULL)){
        printf("queue empty\n");
    }
    else{
        printf(" front: %d\n",front->data);
        printf(" end: %d\n",end->data);
   for(node* tempp=front;tempp!=NULL;tempp=tempp->next){
       printf("%d ",tempp->data );
   }
   printf("\n");}
}
int main(void){   
    char func=0;
    int data;
    int priority;
    while (func!='0'){//'x' will end the program
        scanf("%c",&func);//fxns to be called on the basis of whats input is given
        if (func=='i'){
            scanf("%d" ,&data);//element to be pushed in stack taken as input
            scanf("%d",&priority);
            enqueue(data,priority);//calling function
        }
        else if (func=='x'){
            int d=dequeue();//calling function
            printf("%d\n",d);

        }
        else if(func=='t'){
            print();
        }
        fflush(stdin);
    }
    while(front!=NULL) dequeue();
    return 0;
}

//!!!code triend for char is below..it wasnt working

// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// struct Node 
// {
//     char data; 
//     int priority;
//     struct Node *next;
// };
// typedef struct Node node;
// node *front=NULL;
// node *end =NULL;

// void enqueue(char data,int priority){
//     node* ptr=malloc(sizeof(node));//declared node that will store the data
//     ptr->data=data;
//     ptr->priority=priority;
//     if((front==NULL)){//empty stack condition
//         ptr->next=NULL;
//         front=ptr;
//         end=ptr;
//     }
//     else if((front->priority)<priority){
//         ptr->next=front;
//         front=ptr;
//     }
//     else if(end->priority>priority){
//         end->next=ptr;
//         ptr->priority=priority;
//         ptr->next=NULL;
//         end=ptr;

//     }
//     else{
//         node* temp=front;
//         while((temp!=NULL)&&(temp->next->priority>priority)){
//             temp=temp->next;
//         }
//         ptr->next=temp->next;
//         temp->next=ptr;
//     }
// }
// char dequeue(){
//     node* temp=front;
//     if(front==NULL){//empty stack condition
//         printf("empty queue\n");
//         return -1;
//     }
//     else{
//         char x=front->data;
//         front=front->next;

//         free(temp);
//         return(x);
//     }
// }
// // note: use this to see changesin queue
// void print(){
//     if((front==NULL)){
//         printf("queue empty\n");
//     }
//     else{
//         printf(" front: %c\n",front->data);
//         printf(" end: %c\n",end->data);
//    for(node* tempp=front;tempp!=NULL;tempp=tempp->next){
//        printf("%c ",tempp->data );
//    }
//    printf("\n");}
// }
// int main(void){   
//     char func=0;
//     char data;
//     int priority;
//     while (func!='0'){//'x' will end the program
//         scanf("%c",&func);//fxns to be called on the basis of whats input is given
//         if (func=='i'){
//             scanf("%c" ,&data);//element to be pushed in stack taken as input
//             scanf("%d",&priority);
//             enqueue(data,priority);//calling function
//         }
//         else if (func=='x'){
//             int d=dequeue();//calling function
//             printf("%c\n",d);

//         }
//         else if(func=='t'){
//             print();
//         }
//         fflush(stdin);
//     }
//     while(front!=NULL) dequeue();
//     return 0;
// }