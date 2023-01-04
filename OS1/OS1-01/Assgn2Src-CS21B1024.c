#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdio.h>
#include <math.h>

#define MAX 100
int count = 0;
int PerfectNum[MAX];

struct node // the node will contain info to be sent to each thread
{
    int i;
    int n;
    int k;
};
typedef struct node th;

bool isPerfect(int val)
{
    int sum = 0;
    for (int i = 1; i <= val / 2; i++)
    {
        if (val % i == 0)
        {
            sum = sum + i;
        }
    }
    if (sum == val)
    {
        return 1;
    }
    return 0;
}

void *runner(void *argt) // argument will be the thread node from which we'll check the perfect no. condition
{
    FILE *ftr;
    // FILE *x;
    // x = fopen("OutMain.log", "a");
    ftr = fopen("OutVal.log", "a");
    th *temp = (th *)argt;
    fprintf(ftr, "Thread: %d\n", temp->i + 1);
    // fprintf(x, "Thread: %d: ", temp->i + 1);
    int n1 = temp->n;
    int k1 = temp->k;
    int i1 = temp->i;
    int lowerLimit = ((n1 / k1) * i1) + 1;        // a denotes lower limit
    int higherLimit = (n1 / k1) * i1 + (n1 / k1); // b denotes higher limit
    if (higherLimit > n1)                         // in case b exceeds the given limit
    {
        higherLimit = n1;
    }
    PerfectNum[count] = -1; // will act as breakpoint for thread identification
    count++;

    for (int j = lowerLimit; j <= higherLimit; j++)
    {
        if (isPerfect(j))
        {
            fprintf(ftr, "%d: Is a perfect number\n", j);
            // fprintf(x, "num%d ", j);
            PerfectNum[count] = j;
            count++;
        }
        else
        {
            fprintf(ftr, "%d: Not a perfect number\n", j);
        }
    }
    // fprintf(x, "\n");
    fclose(ftr);
    // fclose(x);

    pthread_exit(NULL);
}

int main(void)
{
    int n, k;
    FILE *fptr;
    FILE *f2ptr;
    fptr = fopen("OutMain.log", "a");
    f2ptr = fopen("input.log", "r");

    fscanf(f2ptr, "%d %d", &n, &k);

    pthread_t tid;

    for (int i = 0; i < k; i++)
    {

        th temp;
        temp.i = i;
        temp.n = n;
        temp.k = k;

        pthread_create(&tid, NULL, runner, (void *)&temp);

        pthread_join(tid, NULL);
    }

    int i = 0;
    int t = 1;

    while (i < count)
    {
        if (PerfectNum[i] == -1 && t == 1)
        {
            fprintf(fptr, "Thread%d:  ", t);
            t++;
        }
        else if (PerfectNum[i] == -1 && t != 1)
        {
            fprintf(fptr, "\nThread%d:  ", t);
            t++;
        }
        else
        {
            fprintf(fptr, "num%d ", PerfectNum[i]);
        }
        i++;
    }
    fclose(fptr);
    fclose(f2ptr);

    return 0;
}