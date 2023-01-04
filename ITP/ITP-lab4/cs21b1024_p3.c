#include<stdio.h>
int main(void){
    int n,i,j,k,l,m;
    scanf("%d",&n);
    for(i=1;i<n+1;i++){ //no. will be chosen from 1 to n
        k=0;
        for(j=i;j>0;j/=10){ //digits of the no. chosen above willbe chosen one by one in order to find their factorial
            l=1;
            for(m=j%10;m>0;m--) {
                l=l*m; //factorial being calculated of digits one by one
            }  
            k=k+l; //sum of factorial of digits done
          }
        if((k==i)) //if sum of the factorial of no. is equal to the no. chose at the start of loop, it will be printed as per ques
            printf("%d ",i);
        
        }
    }
    
