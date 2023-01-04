#include<stdio.h>
int main(void)
{
    int n,i,a,k;
    i=0;
    k=0;
    scanf("%d",&n);
    do{
        a=1+9*i; //distt frog covers afte last one eg, 1st 1 thn 10,19 28....so on
        k=k+a; //total distt being added
        i=i+1; 
    } while(k<n);//once total disst exceeds given distt it ll stop
    printf("%d",i);//printing total leeps









}