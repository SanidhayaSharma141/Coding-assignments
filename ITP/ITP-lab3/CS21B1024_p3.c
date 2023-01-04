#include<stdio.h>
int main(void)
{
    int n,a,b,c,i;
    scanf("%d",&n);
    i=1;
    b=0; //eligible candtt for voting
    c=0;//non eligible
    do {
    
        scanf("%d",&a);
        ((a>=18))? ((b=b+1)): (c=c+1); //ternary statement used!!!!!
        
        i=i+1;
    }while(i<n+1);

    printf("%d",b);











}