#include<stdio.h>
int decint(int n); //function declared
int main(void){ //main func
    int n;
    scanf("%d",&n);
    decint(n); //function called
    return 0;
}
int decint(int n)
{
    int k[sizeof(int)*8];
    int i,j;
    int p;
    p=0;
    for (i=n;i>=1;i=i/2){ //converting using factorization
        if(i%2==1){
            k[p]=1;
        }
        else{
            k[p]=0;
        }
        p++;
    }
    for(i=p-1;i>=0;i--){ //printing the array from oppositeside and removing the last element as it is always 0
        printf("%d ",k[i]);
    }
    return 0;
}