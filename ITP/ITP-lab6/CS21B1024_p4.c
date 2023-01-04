#include<stdio.h>
int max(int n,int arr[]){//max fxn
    int c=arr[0];
     for(int i=0;i<n;i++){
        if(arr[i]>=c){
            c=arr[i];
        }
    }
    return c;
}
int min(int n,int arr[]){//min fxn
    int c=arr[0];
     for(int i=0;i<n;i++){
        if(arr[i]<=c){
            c=arr[i];
        }
    }
    return c;
}
int main(void)
{
    int n,i,maxx,minn;
    scanf("%d",&n);
    int arr[n];
     do
    {
        scanf("%d",&arr[i]);//taking input
        i++;
    } while (i<n);
    maxx=max(n,arr);
    minn=min(n,arr);
    printf("%d ",minn);
    printf("%d ",maxx);
    return 0;
}