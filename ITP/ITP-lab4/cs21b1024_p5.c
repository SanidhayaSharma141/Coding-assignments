#include<stdio.h>
int main(void)
{
    int a,b,i,j,k;
    scanf("%d %d",&a,&b);
    if((a==0)||(b==0)){
        printf("natural no.s not entered");//as per ques natural no.s needs to be entered 
    }

    else if(a>b){//case 1
        for (i=b;i>0;i--){ //it will check gcd from the highest possible no. that can be checked so that one we get the greatest common divisior, the other divisors arent printed
            j=a%i;//remainder checking, if 0 , its divisible
            k=b%i;//remainder checking, if 0 , its divisible
            if((j==0)&&(k==0)){//both should be divisible
                printf("%d",i);
                break;
            }
        }}
    else if(b>=a) {//case 2 with same procedure just codition changed
        for (i=a;i>0;i--){
            j=a%i;
            k=b%i;
            if((j==0)&&(k==0)){
                printf("%d",i);
                break;
            }
    }}
    
}