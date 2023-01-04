//NOTE!!-i didnt understand why was the matrix shown in the output of 1st ques was in random way..i.e it was 222773755 not 222355777
#include<stdio.h>
#include<math.h>
int prfarr(int c,int arr[30]){//fxn if it is a perfect square so that matrix can be printed
    int p=sqrt(c);
    int r=0;
    int arrfinal[p][p];
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++){
            arrfinal[i][j]=arr[r];
            printf("%d ",arrfinal[i][j]);//printing matrix index by index
            r++;
        }
        printf("\n");
    }
    return 0;
}

int main(void)
{
    int n;
    int p;
    int arr[30];
    scanf("%d",&n);
    int c=0;
    for(int i=2;n>1;i++){
        while(n%i==0){//if it will be factor
            arr[c]=i;//storing them in a array of size 30 as it is told to be assumed that max 30 prime factors can be there
            c=c+1;//counting!!
            n=n/i;//n will get reduced once a pf is taken
        }
    }
    p=sqrt(c);//it will store only integer eg if c is 3, sqrt(3) will be 1 only not 1.73 as data type of p is int
    if(sqrt(c)==p){//as float!=int
        prfarr(c,arr);//fxn called
    }
    else{
        printf("%d :(",c);//else condn
    }
    return 0;
}