#include<stdio.h>
#include<math.h>
int mathtest(int n){
    int k[n],i,a,b,c,l;
    a=0;//will count no. of even
    c=0;//will count no. of odd
    b=n;//will count no. of perfect square
    do
    {
        scanf("%d",&k[i]);//no.s input taken one by one
        i++;
    } while (i<n);
    
    for(i=0;i<n;i++){
        if(k[i]%2==0){ //condn for even
            a=a+1;//even count will increment
            b=b-1;//odd count will decrease
        }
        l=sqrt(k[i]);// l is declared integer so it will take integer value from the sqrt if sqrt ifs float
        if(l==sqrt(k[i])){//as l is integer value taken, if sqrt is float it would be diff so it wont be perfect square otherwise it ll be perfect square
            c=c+1;
        }

    }
    printf("%d\n",a);//printing
    printf("%d\n",b);
    printf("%d\n",c);
    return 0;
}
int main(void){//main func
    int n;
    scanf("%d",&n);
    mathtest(n);//function called
    return 0;
}