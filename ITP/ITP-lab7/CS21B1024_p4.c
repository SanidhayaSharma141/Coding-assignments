#include<stdio.h>
#include<string.h>
static int count=0;//it will work as index equivalent to no. of recursions-1
int k[sizeof(int)*8];//global array fotmed where binar form will be stored in reverse order
int bin(int num){//fxn introduced
    int i;
    if(num%2==1){
        k[count]=1;
    }
    else{
        k[count]=0;
    }
    count++;
    if(num/2>=1){
        bin(num/2);//if condition is true recursion will occur
    }
    else{
        for(i=count-1;i>=0;i--){ //printing the array from oppositeside and removing the last element as it is always 0
        printf("%d",k[i]);
    }
    }
    return 0;
}
int main(void)//main fxn
{
    int num;
    scanf("%d",&num);
    bin(num);
    return 0;
}
