//,sanidhaya sharma roll no. cs21b1024
//cs21b1024 problem 4
#include<stdio.h>
int main(void)
{
    int num,i,j;

    printf("Enter number: ");
    scanf("%d", &num);

    for(i=num; i>=1; i--)
    {

        for(j=num; j>i; j--)
        {
            printf("%d", j);
        }

        
        for(j=1; j<=(i*2-1); j++)
        {
            printf("%d", i);
        }
        for(j=i+1; j<=num; j++)
        {
            printf("%d", j);
        }

        printf("\n");
    }

    for(i=1; i<num; i++)
    {
      
        for(j=num; j>i; j--)
        {
            printf("%d", j);
        }

    
        for(j=1; j<=(i*2-1); j++)
        {
            printf("%d", i+1);
        }

      
        for(j=i+1; j<=num; j++)
        {
            printf("%d", j);
        }

        printf("\n");
    }
return 0;
}