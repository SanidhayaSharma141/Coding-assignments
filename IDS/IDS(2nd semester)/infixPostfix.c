// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// struct node
// {

// char data;
// struct node *next;


// }*top=NULL,*pstart=NULL;
// /*-------------------- insertion in postfix expression linked list -------*/


// void insert(char ch)
// {
// struct node *t,*baby;
//     baby=(struct node *)malloc(sizeof(struct node));
//     baby->next=NULL;
//     baby->data=ch;
//     t=pstart;

//     if(pstart==NULL)
//     {
//     pstart=baby;
//     }
//     else
//     {
//     while(t->next!=NULL)
//     t=t->next;
//     t->next=baby;

//     }
//     //printf(" inserted in list- %c",baby->data);

// }

// /* --------- push operation ------- */



// void push (char symbol)
// {

//     struct node *p;
//     p=(struct node *)malloc(sizeof(struct node));
//     p->data=symbol;
//     if(top==NULL)
//     {
//      top=p;
//      p->next=NULL;

//     }
//     else
//     {

//     p->next=top;
//     top=p;

//     }
// }

// char  pop()
// {
// struct node *x,*y;
// char k;
// if(top==NULL)
// {
//     printf("stack underflow\n");
//     return 0;

// }
// else
// {
// x=top;
// top=top->next;
// k=x->data;
// //printf("node %d is deleted\n",top->data);
// free(x);
// x=NULL;
// return k;


// }



// }


// void displaypost()
// {
//     struct node *to;
//     if(pstart==NULL)
//     printf("");
//     else
//     {
//     to=pstart;
//     while(to!=NULL)
//     {
//         printf("%c",to->data);
//         to=to->next;

//     }

//     }


// }


// /*============== precedence selector ================= */

// int precedence(char ch)
// {

// if(ch=='^')
// return (5);
// else if(ch=='*' || ch== '/')
// return (4);
// else if (ch== '+' || ch== '-')
// return (3);
// else
// return (2);
// }


// /*=================== infix to postfix conversion ================ */

// void intopost(char infix[])
// {

//     int len;
//     int index=0;
//     char symbol,temp;
//     len= strlen(infix);
//     //printf("%d",len);
//     while(len>index)
//     {
//         symbol=infix[index];

//         switch(symbol)
//         {

//         case '(':
//         push(symbol);
//         break;

//         case ')':
//         // temp=pop();
//         while(temp!='(')
//         {
//         insert(temp);
//         temp=pop();
//         }
//         break;

//         case '^':
//         case '+':
//         case '-':
//         case '*':
//         case '/':
//         if(top==NULL)
//         {
//             push(symbol);
//     //      break;

//         }
//         else
//         {
//         while(top!=NULL && (precedence(top->data)>=precedence(symbol)))
//         {
//             temp=pop();
//             insert(temp);

//         }
//         push(symbol);

//         }   
//         break;
//         default:
//         insert(symbol);

//          }
//          index=index+1;


//     }
//     while(top!=NULL)
//     {
//     temp=pop();
//     insert(temp);

//     }
//     displaypost();
//     return;




// }


// int main()
// {
// char infix[50];
// scanf("%s",infix);
// intopost(infix);
// getchar();
// return 0;
// }

// C program to convert infix expression to postfix
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Stack type
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};

// Stack Operations
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*)
        malloc(sizeof(struct Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;

    stack->array = (int*) malloc(stack->capacity *
                                sizeof(int));

    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}
char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}


// A utility function to check if
// the given character is operand
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z');
}

// A utility function to return
// precedence of a given operator
// Higher returned value means
// higher precedence
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}


// The main function that
// converts given infix expression
// to postfix expression.
int infixToPostfix(char* exp)
{
    int i, k;

    // Create a stack of capacity
    // equal to expression size
    struct Stack* stack = createStack(strlen(exp));
    if(!stack) // See if stack was created successfully
        return -1 ;

    for (i = 0, k = -1; exp[i]; ++i)
    {

        // If the scanned character is
        // an operand, add it to output.
        if (isOperand(exp[i]))
            exp[++k] = exp[i];

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (exp[i] == '(')
            push(stack, exp[i]);

        // If the scanned character is an ‘)’,
        // pop and output from the stack
        // until an ‘(‘ is encountered.
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1; // invalid expression			
            else
                pop(stack);
        }
        else // an operator is encountered
        {
            while (!isEmpty(stack) &&
                Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }

    }

    // pop all the operators from the stack
    while (!isEmpty(stack))
        exp[++k] = pop(stack );

    exp[++k] = '\0';
    printf( "%s", exp );
}

// Driver program to test above functions
int main()
{
    char exp[] = "a*b+(c*d)";
    infixToPostfix(exp);
    return 0;
}