#include<stdio.h>
int stackspan(int a) //function
{
    int k[a];
    int out[a];
    int c,p,j;
    int i=0;
    do
    {
        scanf("%d",&k[i]); //taking input in an array n no. of times
        i++;
    } while (i<a);
    
    for(p=0;p<a;p++){
        c=1;
        for(j=p;j>0;j--){
            if ((k[j]<=k[p])&&(k[j-1]<=k[p]))//checking condition of span
            {
                c=c+1; //counting span each time
            }
        }
        out[p]=c;//c will be stored in respective index and c will again be changed for other index as per condition above
    }
    for(int i=0;i<a;i++){
        printf("%d ",out[i]); //printing the span array
    }
    return 0;
}
int main(void){//main function
    int n;
    scanf("%d",&n);
    stackspan(n); //the function asked
    return 0;
}