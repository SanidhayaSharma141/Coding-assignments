// <CS21B1024> <SANIDHAYA SHARMA>
//<CS21B1024_P3.c>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sumMEM=10;
int c=0;
struct Node 
{
    int MEM;
    int MUL;
    int MOD;
    struct Node *next;
};
typedef struct Node node;
node *front=NULL;
node *end=NULL;
void enqueue(int MEM,int MUL,int MOD){
    node* ptr=malloc(sizeof(node));//declared node that will store the data
    ptr->MEM=MEM;
    ptr->MUL=MUL;
    ptr->MOD=MOD;
    ptr->next=NULL;
    if((front==NULL)&&(end==NULL)){//empty queue condition
        front=ptr;
        end=ptr;
    }
    else{
        end->next=ptr;
        end=end->next;//now top will point to the newly added node
    }
}
void dequeue(){
    node* temp=front;
    if(front==NULL){//empty queue condition
        printf("empty queue\n");
    
    }
    else{
        front=front->next;
        if(front==NULL){
            end=NULL;
        }

        free(temp);
    }
}

int addMEM(int num){
    sumMEM=sumMEM+num;
    return(sumMEM);
}
int calmem(int MUL,int MOD,int addmem){
    int a=(MUL*addmem)%MOD;
    return(a);

}
// void print(){
//     if((front==NULL)&&(end==NULL)){
//         printf("queue empty");
//     }
//     else{
//    for(node* tempp=front;tempp!=NULL;tempp=tempp->next){
//        printf("%d ",tempp->MEM );
//        printf("%d ",tempp->MUL );
//        printf("%d \n",tempp->MOD );
//    }
//    printf("\n");}
// }


int main(void){   
    int MUL=1;
    int MOD;
    int MEM;
    while(MUL!=0){
        scanf("%d",&MUL);
        if(MUL==0){
            break;
        }
        scanf("%d",&MOD);
        if(c==0){
            MEM=calmem(MUL,MOD,10);
        c++;}
        else{
            MEM=calmem(MUL,MOD,addMEM(end->MEM));
        }
        enqueue(MEM,MUL,MOD);
        printf("%d\n",end->MEM);
        // print();

    }
    while(front!=NULL){
        dequeue();
    }
    return 0;

}
