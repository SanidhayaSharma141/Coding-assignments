#include<stdio.h>
int main(void)
{
    int n,i,j; //n is the no.,j at the end would be sum
    j=0;
    scanf("%d",&n);
    for(i=n;n>0;n/=10)
    {
        j+=(n%10);
    }
    printf("%d",j);

}