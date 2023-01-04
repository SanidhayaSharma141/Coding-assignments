#include<stdio.h>
int main(void){
    int n,i,j,a,b,count;
    int arr[n];
    i=0;
    printf("Number of elements: ");
    scanf("%d",&n);
    printf("Elements are: ");
    do
    {
        scanf("%d",&arr[i]);
        i++;
    } while (i<n);
    printf("Unique elements are: ");
    for(a=0;a<n;a++){
        count=0;
        for(j=0;j<n;j++){
            if(arr[a]==arr[j]){//checking if two elements are equal, if yes then c will increment.NOTE!!- once c will get increment for sure when it will be equal when i=a, eg k[3]=k[3] when i=a=3
                count=count+1;
            }
        }
        if(count==1){
            printf("%d ",arr[a]); //condition check
        }
    }
    printf("\n");
    a=arr[0];
    for(i=1;i<n;i++){
        if(a<arr[i]){
            a=arr[i];
            b=i;
        }
        }
    printf("second largest no. is: %d and its position is %d\n",a,b);
    


    
    
    return 0;
}