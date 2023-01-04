#include<stdio.h>
#include<stdbool.h>
  static int counter=0;
bool chemdogpar(int arr[],int i, const int m){
    counter++;
    if(arr[i]==arr[i]%m){
        if(counter%2==0){
            return true;
            }
        else{
            return false;
        }
    }
    else{
        arr[i]=arr[i]%m;
        chemdogpar(arr,arr[i],m);
    }

}
int main(void)
{
    int i,n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int count=chemdogpar(arr,n-1,m);
    if(count==1){
        printf("cheemu");
    }
    else{
        printf("doge");
    }
    /*for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }*/ //just for confirmation of the array as shown in ques
    return 0;
}
