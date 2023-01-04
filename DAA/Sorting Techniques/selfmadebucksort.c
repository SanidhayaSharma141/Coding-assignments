#include <stdio.h>
#include <stdlib.h>
#define bucklen 10
struct Node
{
    float data;
    struct Node *next;
};
typedef struct Node node;
int gbuckind(float k)
{
    return k * 10;
}
void printBuckets(struct Node *list)
{
    struct Node *cur = list;
    while (cur)
    {
        printf("%0.2f ", cur->data);
        cur = cur->next;
    }
}
node *insertionsort(node *list)
{
    if (list == NULL || list->next == NULL)
    {
        return list;
    }
    node *nl, *k;
    nl = list;
    k = list->next;
    nl->next = NULL;
    while (k != NULL)
    {
        node *ptr;
        if (nl->data > k->data)
        {
            node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = nl;
            nl = tmp;
            continue;
        }

        for (ptr = nl; ptr->next != NULL; ptr = ptr->next)
        {
            if (ptr->next->data > k->data)
            {
                break;
            }
        }
        if (ptr->next != NULL)
        {
            node *tmp = k;
            k = k->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        }
        else
        {
            ptr->next = k;
            k = k->next;
            ptr->next->next = NULL;
            continue;
        }
    }
    return nl;
}
void BucketSort(float arr[], int n)
{
    int i, j;
    node **buckets;
    buckets = (node **)malloc(sizeof(node *) * (bucklen));
    for (int i = 0; i < bucklen; i++)
    {
        buckets[i] = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        node *current;
        int p = gbuckind(arr[i]);
        current = (node *)malloc(sizeof(node));
        current->data = arr[i];
        current->next = buckets[p];
        buckets[p] = current;
    }
    printf("-------------\n");
    printf("Bucktets before sorting\n");
    for (i = 0; i < bucklen; i++)
    {
        printf("Bucket[%d]: ", i);
        printBuckets(buckets[i]);
        printf("\n");
    }
    for (int i = 0; i < bucklen; i++)
    {
        buckets[i]=insertionsort(buckets[i]);
    }
    printf("-------------\n");
    printf("Bucktets after sorting\n");
    for (i = 0; i < bucklen; i++)
    {
        printf("Bucket[%d]: ", i);
        printBuckets(buckets[i]);
        printf("\n");
    }
    for (j = i = 0; i < bucklen; i++)
    {
        node *nt;
        nt = buckets[i];
        while (nt)
        {
            arr[j++] = nt->data;
            nt = nt->next;
        }
    }
}
void print(float ar[])
{
    int i;
    for (i = 0; i < 7; ++i)
    {
        printf("%0.2f ", ar[i]);
    }
    printf("\n");
}
int main(void)
{
    float array[7] = {0.42, 0.32, 0.99, 0.63, 0.27, 0.27, 0.52};

    printf("Initial array: ");
    print(array);
    printf("-------------\n");

    BucketSort(array, 7);
    printf("-------------\n");
    printf("Sorted array: ");
    print(array);
    return 0;
}