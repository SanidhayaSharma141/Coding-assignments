#include<stdio.h>
int main(void){
    int n,i,j,k,l;
    scanf("%d",&n);
    for(i=0;i<n+1;i++){
        for(j=0;j<=i;j++){  //using nested for loops
            printf("*"); //as * gets printed once in first line in left side aand gets printed one more time than previous
        }
        for(k=2*(n-i);k>0;k--){ //as # starts with getting printed twice times no. given and then is printed 2 times less each time thereafter
            printf("#");
        }
        for(l=0;l<=i;l++) { //similar pattern as of left side in right side
            printf("*");
        }
        printf("\n");//starting new line now
        }

    }

    
