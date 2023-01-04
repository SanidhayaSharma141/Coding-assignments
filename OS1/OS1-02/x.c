/*
 name: Sanidhaya Sharma
Roll No: CS21B1024
Assignment 1: OS 1
*/
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
// #include <sys/wait.h>
// #include <sys/ipc.h>
// #include <sys/shm.h>
#include <string.h>
#include <stdlib.h>

bool is_Perfect(int val) // function to check whether the given number is perfect or not
{
    int sum = 0;
    int temp = val;
    int i = 1;
    while (i <= val / 2)
    {
        if (val % i == 0)
        {
            sum = sum + i;
        }
        i++;
    }

    if (val == sum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    FILE *fptr;
    fptr = fopen("OutMain.txt", "a");
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int cycle_number = 0;
    int lowerLimit = 1;
    int higherLimit = n / k;
    for (int i = 1; i <= k; i++)
    {
        if (fork() == 0) // child process
        {
            fprintf(fptr, "P%d: ", cycle_number + 1);
            for (int i = lowerLimit; i <= higherLimit; i++)
            {
                if (is_Perfect(i))
                {
                    fprintf(fptr, "%d ", i);
                }
                // printf("%d " , i);
            }
            fprintf(fptr, "\n");
            exit(0);
        }
        cycle_number++;
        lowerLimit = (n / k) * cycle_number + 1;
        higherLimit = lowerLimit + (n / k) - 1;
        wait(NULL); // child process called
    }
    fclose(fptr);

    return 0;
}
