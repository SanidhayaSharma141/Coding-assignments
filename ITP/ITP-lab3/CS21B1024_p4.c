#include<stdio.h>
int main(void) {
    int a,b,c,d,i;
    a=0;
    b=0;//b represents no. of times -ve no. entered
    c=0;//c represents no. of times 0 entered
    d=0;//d represents no. of times +ve no. entered
    do
    {
        scanf("%d",&a);   //do while used!!!!!
        if ((a>0))
        {
            d=d+1;
        }
        else if((a<0)){
            b=b+1;
        }
        else{
            c=c+1;
        }
        
    } while ((a!=-1));
    printf("%d %d %d",d,b,c);
    







}