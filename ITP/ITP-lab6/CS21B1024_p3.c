#include<stdio.h>
#include<math.h>
//trace fxn initialised
int trace(int arr){//it will take sum of the input(input will be the array index element where i=j)
    static int c=0;
    c=c+arr;
    
    return c;

}
//frequency fxn initialised
int freq(int n){//each element of the square matrix will come to this function and it will check if it is odd, and if it satisfies, count will increment each time and count will be returned to the main function
    static int c=0;
    if(n%2!=0){
        c=c+1;//c is 0(static!!) earlier but will increment  if condition holds true for the 2d array
     }
    return c;
}
int main(void)
{
    int n;
    int i=0;
    int j=0;
    int sum;
    int count=0;
    scanf("%d",&n);
    int arr[n][n];
    int *arptr=&arr;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);//input taken
        }

    }
    for(int k=0;k<n;k++){
        sum=trace(arr[k][k]);//sum will come after trace function as c will be returned
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            count=freq(arr[i][j]);
            }
        }
    
    printf("%d",sum);//trace printed
    printf("\n");
    printf("%d",count);//frequency printed
    return 0;
}