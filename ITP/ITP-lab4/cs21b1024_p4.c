#include<stdio.h>
int main(void){
    int n,i,j,k,l;
    k=1;
    scanf("%d",&n);//no. of horizontal lines 
    for(i=1;i<n+1;i++){//lines one by one
        for(l=2*(n-i);l>0;l--){//spaces before the elements  eg before 1 there are some spaces for the pattern
            printf(" ");
        }
        for(j=0;j<i;j++){//no.s will be printed same no. of timesa s th line no. is eg in 7th line there will be 7 elements
            printf("%d",k);
            if(k<100){
                printf("  ");//as in pattern when the are 2 digit no.s the spaces between them is 2 times whereas when three digits no.s come, the space b/w no.s is only once
            }
            else{
                printf(" ");//in case of 3 digit no.s the space betwwn two consecutive elements is only once
            }
            k=k+5;
        }
        printf("\n");//for next line
    }}
