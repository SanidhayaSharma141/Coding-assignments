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
node* tail=NULL;

node *addemp(int data)
{ // for adding to empty list
    node *tmp = malloc(sizeof(node));
    tmp->last = tmp;
    tmp->data = data;
    tmp->next = tmp;
    return tmp;
}
node *addemp(int data)
{ // for adding to empty list
    node *tmp = malloc(sizeof(node));
    tmp->last = tmp;
    tmp->data = data;
    tmp->next = tmp;
    return tmp;
}
node *insertatbeg(int data)
{
    node *p = addemp(data);
    if (tail == NULL)
    { // null case
        tail = p;
    }
    else
    {
        node *tmp = tail->next; // nodes declared
        node *tmp1 = tmp->next;
        p->last = tail;
        p->next = tmp;
        tmp->last = p;
        tail->next = p;
        return tail;
    }
}

node *insertatend(int data)
{
    node *p = addemp(data);
    if (tail == NULL)
    { // null case
        tail = p;
    }
    else
    {
        node *tmp = tail->next; // nodes declared
        node *tmp1 = tmp->next;
        p->last = tail;
        p->next = tmp;
        tmp->last = p;
        tail->next = p;
        tail=p;
        return tail;
    }
}
void del(int num)
{ // fxn for deletion of specific data from the linked list
    int count = 0;
    node *temp = tail->next;  // node initialised
    node *temp2 = temp->next; // node initialised 2nd node
    node *temp1 = tail->last; // node initialised second last node
    if (num == temp->data)
    { // if 1st node is to be deleted
        tail->next = temp2;
        temp->next->last = tail;
        free(temp);
    }
    else if (num == tail->data)
    { // if last node is to be deleted
        temp1->next = tail->next;
        tail->next->last = temp1;
        free(tail);
        tail = temp1;
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
            }
            else
            {
                temp = temp->next; // otherwise it ll continue traversing
                temp2 = temp2->next;
            }
        } while ((temp != tail->next) && (count == 0));
    }
}

void printdata(){
    if(tail==NULL){
        printf("no node");
        }
    else{
            node*temp=tail->next;
            do{
                printf("%d ",temp->data);
                temp=temp->next;
            }while(temp!=tail->next);
        }

}
void neighbours(int num)
{
    if (tail == NULL)
    { // null case
        printf("No elements/null");
    }
    else
    {
        node *temp = tail->next; // node initialised
        do
        {
            if (temp->data == num)
            { // while traversing, once it finds the data=data of node,it ll print last and next as the neighbour
                printf("%d %d", temp->last->data, temp->next->data);
                return;
            }
            temp = temp->next;
        } while (temp != tail->next);
    }
}