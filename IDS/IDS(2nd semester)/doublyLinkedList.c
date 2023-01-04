#include<stdio.h>
#include<stdlib.h> //included lib
#include<math.h>

struct Node //initialised a linked list
{
    struct Node *last;
    int data; 
    struct Node *next;
};

typedef struct Node node;
node * head=NULL;
node* tail=NULL;

node *addemp(int data)
{ // for adding to empty list
    node *tmp = malloc(sizeof(node));
    tmp->last = NULL;
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

void insertatbeg(int data)
{
    node *p = addemp(data);
    if ((tail == NULL)&(head==NULL))
    { // null case
        tail = p;
        head =p;
    }
    else
    {   node * temp=head;
        p->last = NULL;
        p->next = head;
        temp->last=p;
        head=p;
    }
}
void insertatend(int data)
{
    node *p = addemp(data);
    if ((tail == NULL)&(head==NULL))
    { // null case
        tail = p;
        head= p;
    }
    else
    {   node* temp=tail;
        p->last = tail;
        p->next = NULL;
        temp->next = p;
        tail=p;
    }
}
int del(int num)
{ // fxn for deletion of specific data from the linked list
    int count = 0;
     node* temp=head;
     node* temp3=tail;
     node* temp2=head->next;
    node *temp1 = tail->last; // node initialised second last node
    if (num == head->data)
    { // if 1st node is to be deleted

        head= head->next;
        free(temp);
    }
    else if (num == tail->data)
    { // if last node is to be deleted
        tail->last->next=NULL;
        tail = temp1;
        free(temp3);
    }
    else
    {
        do
        {
            if (temp->data == num)
            { // traversing till we find the data in linked list
                node *temp2 = temp->last;
                temp2->next = temp->next;
                temp->next->last = temp2;
                free(temp);
                count++;
                return 0;
            }
            else
            {
                temp = temp->next; // otherwise it ll continue traversing
                temp2 = temp2->next;
            }
        } while ((temp !=NULL) && (count == 0));
        printf("not found");
    }

}

void printdata(){
    if(tail==NULL){
        printf("no node");
        }
    else{
            node*temp=head;
            do{
                printf("%d ",temp->data);
                temp=temp->next;
            }while(temp!=NULL);
        }

}
int main(void)
{
    char func = 0;
    int data;
    while (func != 'x')
    {                       //'x' will end the program,though it is not written
        scanf("%c", &func); // fxns to be called as per the insert
        if (func == 'i')
        {
            scanf("%d", &data); // element to be inserted taken as insert
            insertatbeg(data);       // calling function
        }
        else if (func == 'b')
        {
            scanf("%d", &data); // element to be inserted taken as insert
            insertatend(data);       // calling function
        }

        else if (func == 'd')
        {
            scanf("%d", &data); // element to be deleted taken as insert
            del(data);          // calling function
        }
        // NOTE!!!!!!!!!-use this for any confusion( to print the linked list)
        else if(func=='p'){
            printdata();
        }
        fflush(stdin);
    }
    return 0;
}