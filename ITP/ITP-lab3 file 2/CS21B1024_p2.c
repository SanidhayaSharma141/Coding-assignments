#include<stdio.h>


int main(void) {
    int n,a,b,c,d,i;
    scanf("%d",&n);
    i=1;
    while(i<n+1) {
        switch((i%35)) { //check divisible by both 7 n 5
            case 0:
                printf("cheema doge\n");
                break;
            default:
                switch((i%5)){   //check divisible by 5
                    case 0:
                        printf("cheema\n");
                        break;
                    default:
                        switch((i%7)){ //check divisible by 7
                            case 0:
                                printf("doge\n");
                                break;
                            default:
                                printf("%d\n",i); //if not divisible by  both
                        }

                }

        }
            i++;






    }

















}
