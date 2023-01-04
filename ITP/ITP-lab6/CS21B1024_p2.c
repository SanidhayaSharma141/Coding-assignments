#include<stdio.h>
int divmod(int n){//function for modifying
    int a,b;
    a=n/3;
    b=a%5;
    return b;
}
int main(void)
{
    int n;
    int i=0;
    scanf("%d",&n);
    int arr[n];
    int *ptrarr=&arr;//pointer
    do
    {
        scanf("%d",&arr[i]);//taking input
        i++;
    } while (i<n);
    for(int j=0;j<n;j++){
        *(ptrarr+j)=divmod(arr[j]);//calling func
    }
    for(int k=0;k<n;k++){
        printf("%d ",*(ptrarr+k));//acccessing uding pointer
    }
    return 0;
}