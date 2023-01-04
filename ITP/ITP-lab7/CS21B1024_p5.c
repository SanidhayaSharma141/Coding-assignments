#include<stdio.h>
int c=0;
long sum(int num){//fxn for product of factorials
    long prdct=1;
    int i;
    for(i=num;i>0;i--){
        prdct=prdct*fact(i);//fact fxn called
    }
    return prdct;
}
int fact(int num){//fact fxn
   if (num == 1){
        return 1;
    }
    else if (num>1){
        return(num*fact(num-1));//recursion!!!!
    }
}

int main(void)
{
    long num;
    long mod;
    scanf("%ld",&num);
    scanf("%ld",&mod);
    long out=sum(num);
    long ans=out%mod;//modulus taken
    printf("%ld",ans);
    return 0;
}//note;i didnt take double as we are not taught of finding mod of doubles
