#include<bits/stdc++.h>
using namespace std;

struct adjNode{
    int data;
    adjList* 
};
typedef struct ST{
    struct ST* next;
    struct adjNode* node;
    ST(struct ST* next,struct adjNode* node){
        this->next=next;
        this->node=node;
    }
} stack;