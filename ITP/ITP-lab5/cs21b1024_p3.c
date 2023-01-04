#include<stdio.h>
int unique(int n){ //fuction declared
    int k[n];//array
    int i,a,b,c;
    i=0;
    do
    {
        scanf("%d",&k[i]);//no.s input taken one by one
        i++;
    } while (i<n);
    for(i=0;i<n;i++){
        c=0;
        for(a=0;a<n;a++){
            if(k[i]==k[a]){//checking if two elements are equal, if yes then c will increment.NOTE!!- once c will get increment for sure when it will be equal when i=a, eg k[3]=k[3] when i=a=3
                c=c+1;
            }
        }
        if(c==1){
            printf("%d ",k[i]); //condition check
        }
    }
    return 0;
}
int main(void){//main fxn
    int n;
    scanf("%d",&n);
    unique(n);//function asked in main fxn
    return 0;
}