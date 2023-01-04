#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int b=1;//will be deciding whether popped value needs to be printed..else it prints -1 of return -1 in pop/popend fxn
struct Node //created a struct for linked list that will act as stack
{
    int data; 
    struct Node *next;
};
typedef struct Node node;
node *top1=NULL;
node *top2=NULL;
node *top3=NULL;//it will act as previous of top2...
/*i have used 1 stack where i have given top as top1 and i have initialised pointer top2 which points
 to first value that was pushed into the stack...eg.
 if user enters 1 as the first node top1 and top2 points to it..then if 2 is entered then top1 points to 2 and top2 points to 1..similarly 3,4,5,6 are added in sorted way..top1 points to 6 and top2 points to 1..
 now if user wants to push and pop from the end(stack 
 implementation), he can use stack functions using pushend(where top2 will act as top of stack)..
 eg. user pushes 7 using pushend, then top2 now points to 7,not1 and if user pops from end using popend, 7 will be popped

 if user wants to push or pop from front, he can use stack implementation using push and pop(where 
 top1 act as top of stack)
 eg. user pushes 8 using push, then top1 now points to 8,not6 and if user pops from start, 8 will be popped

 I hope you understood:)
*/

void enqueue(int opt,int data){

}
void push(int data){
    node* ptr=malloc(sizeof(node));//declared node that will store the data
    ptr->data=data;
    if((top1==NULL)&& (top2==NULL)){//empty stack condition
        ptr->next=NULL;
        top1=ptr;
        top2=ptr;
    }
    else{
        ptr->next=top1;
        top1=ptr;//now top1 will point to the newly added node
    }
}
void pushend(int data){
    node* ptr=malloc(sizeof(node));//declared node that will store the data
    ptr->data=data;
    if((top1==NULL)&& (top2==NULL)){//empty stack condition
        ptr->next=NULL;
        top1=ptr;
        top2=ptr;
    }
    else{
        top3=top2;//it will be previous value of top2(as it will change to next so i ll be using this value while popping)
        top2->next=ptr;
        top2=top2->next;//now top2 will point to the newly added node
        top2->next=NULL;
    }
}
//pop fxn
int pop(){
    node* temp=top1;
    int x;
    if((top1==NULL)&&(top2==NULL)){//empty stack condition
        printf("stack underflow\n");
        b=0;
        return -1;
    }
    else if(top1==top2){
        b=1;
        x=top1->data;
        top1=NULL;
        top2=NULL;
    }
    else if(top1->next==top2){
        b=1;
        x=top1->data;
        top1=top2;
        free(temp);
    }
    else{
        b=1;
        x=temp->data;
        top1=top1->next;
        free(temp);
    }
    return x;
}
int popend(){
    node* temp=top2;
    int x;
    if((top1==NULL)&&(top2==NULL)){
        b=0;
        printf("stack underflow\n");
        return -1;
    }
    else if(top2==top1){
        b=1;
        x=top1->data;
        top1=NULL;
        top2=NULL;
    }
    else if(top2==top1->next){
        b=1;
        x=top2->data;
        top2=top1;
        free(temp);
    }
    else{
        b=1;
        x=temp->data;
        top2=top3;
        free(temp);
    }
    return x;
}
// note: use this to see changesin queue
void print(){
    if((top1==NULL)&&(top2==NULL)){
        printf("queue empty");
    }
    else{
        printf(" top1: %d\n",top1->data);
         printf(" top2: %d\n",top2->data);
   for(node* tempp=top1;tempp!=NULL;tempp=tempp->next){
       printf("%d ",tempp->data );
   }
   printf("\n");}
}

int main(void){   
    char func=0;
    int data;
    int opt;
    int value;
    while (func!='x'){//'x' will end the program
        scanf("%c",&func);//fxns to be called on the basis of whats input is given
        if (func=='e'){
            scanf("%d" ,&opt);
            scanf("%d" ,&data);//element to be pushed in stack taken as input
            if(opt==0){
                pushend(data);
            }
            else if(opt==1){
                push(data);
            }
        }
        else if (func=='d'){
            scanf("%d",&opt);
            if(opt==0){
                value=pop();
                if(b==1){
                    printf("%d\n",value);
                }

            }
            else if(opt==1){
                value=popend();
                if(b==1){
                    printf("%d\n",value);
                }
            }

        }
        else if(func=='t'){
            print();
        }
        fflush(stdin);
    }
    while(top1!=NULL) pop();
    return 0;
}