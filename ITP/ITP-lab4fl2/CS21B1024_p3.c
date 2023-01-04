#include<stdio.h>
#include<math.h>
int main(void){
    int n,i,j,a,b,c,l;
    int arr[sizeof(int)*8];
    i=0;
    b=0;
    printf("Enter input: ");
    do
    {
        scanf("%d ",&a);
        if((a==0)||(a==1)){
            arr[i]=a;
            b=b+1;
        }
        i=i+1;
    } while(a!=-1);
    
    for(l=b;l>0;l--){
        c=c+arr[l-1]*pow(10,j);
        j=j+1;
        }
    printf("This will be treated as binary number: %d",c);
    
    
    
    
    return 0;
}