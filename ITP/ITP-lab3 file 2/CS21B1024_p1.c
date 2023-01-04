#include<stdio.h>

int main(void)
{

    int b,c,p,i,x,num; //b refers to age,c refers to income
    //they refer to ticket price which will be set later acc to condn
    char a;//a refers to sex
    i=1;
    x=0;//x will add all the ticket costs of all the people
    scanf("%d",&num);
    while(i<num+1) {
        fflush(stdin);
        scanf("%c %d %d",&a,&b,&c);
        if((c<=1500000)||(b<=18)||(b>=70)) {
            p=0.75*500;
            x=x+p;
        }
        else if((a=='F')||(c<=2500000)){
            p=0.85*500;
            x=x+p;
            }
        else if((c<=5000000)) {
            p=0.95*500;
            x=x+p;
        }
        else{
            p=500;
            x=x+p;}
        i=i+1;
    }
    printf("%d",x);
    }