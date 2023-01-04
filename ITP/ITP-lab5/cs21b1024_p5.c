#include<stdio.h>
static int num=0;//global variable that will be incremented each time control  goes to any function
int nice(){
    num++;//global variable will increment if it enters in this fxn
    static int r=0;//static variable declared
    r=r+1;//count of nice
    return r;//returning count
}
int cool(){
    num++;//global variable will increment if it enters in this fxn
    static int c=0;//static variable declared
    c=c+1;//count of cool
    return c;//returning count
}
int main(void){
    int n,p,q;
    int i=0;
    scanf("%d",&n);//size of array
    int arr[n];//array
    do
    {
        scanf("%d",&arr[i]);//input of array
        i++;
    } while (i<n);
    for(i=0;i<n;i++){//loop in main
        if(arr[i]%42==0){//condition within loop to call nice and cool fxn
            p=nice(); //return values of fxn assigned
        }
        if(arr[i]%57==0){//condition within loop to call nice and cool fxn
            q=cool(); //return values of fxn assigned
        }
    }
    printf("%d ",p);//printing no. of times nice fxn called
    printf("%d ",q);//printing no. of times cool fxn called
/*  printf("%d",num); --it ll print num's value if needed to print which will be sum of p and q as the control will enter the function p+q times so num will bw incremented to p+q*/
    return 0;
    
}