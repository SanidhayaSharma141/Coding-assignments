#include <stdio.h>
#include <stdlib.h>

#define lengtharr 7   // Array size
#define lenbuck 10  // Number of buckets
#define INTERVAL 10  // Each bucket capacity

struct Node {
  float data;
  struct Node *next;
};

void BucketSort(float arr[]);
struct Node *InsertionSort(struct Node *list);
void print(float arr[]);
void printBuckets(struct Node *list);
int getBucketIndex(float value);

// Sorting function
void BucketSort(float arr[]) {
  int i, j;
  struct Node **buckets;

  // Create buckets and allocate memory size
  buckets = (struct Node **)malloc(sizeof(struct Node *) * lenbuck);

  // Initialize empty buckets
  for (i = 0; i < lenbuck; ++i) {
    buckets[i] = NULL;
  }

  // Fill the buckets with respective elements
  for (i = 0; i < lengtharr; ++i) {
    struct Node *current;
    int pos = getBucketIndex(arr[i]);
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
  }

  // Print the buckets along with their elements
  for (i = 0; i < lenbuck; i++) {
    printf("Bucket[%d]: ", i);
    printBuckets(buckets[i]);
    printf("\n");
  }

  // Sort the elements of each bucket
  for (i = 0; i < lenbuck; ++i) {
    buckets[i] = InsertionSort(buckets[i]);
  }

  printf("-------------\n");
  printf("Bucktets after sorting\n");
  for (i = 0; i < lenbuck; i++) {
    printf("Bucket[%d]: ", i);
    printBuckets(buckets[i]);
    printf("\n");
  }

  // Put sorted elements on arr
  for (j = 0, i = 0; i < lenbuck; ++i) {
    struct Node *node;
    node = buckets[i];
    while (node) {
      arr[j++] = node->data;
      node = node->next;
    }
  }

  return;
}

// Function to sort the elements of each bucket
struct Node *InsertionSort(struct Node *list) {
  struct Node *k, *nodeList;
  if (list == NULL || list->next == NULL) {
    return list;
  }

  nodeList = list;
  k = list->next;
  nodeList->next = NULL;
  while (k != NULL) {
    struct Node *ptr;
    if (nodeList->data > k->data) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->next != NULL; ptr = ptr->next) {
      if (ptr->next->data > k->data)
        break;
    }

    if (ptr->next != NULL) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = NULL;
      continue;
    }
  }
  return nodeList;
}

int getBucketIndex(float value) {
  return value*INTERVAL;
}

void print(float ar[]) {
  int i;
  for (i = 0; i < lengtharr; ++i) {
    printf("%0.2f ", ar[i]);
  }
  printf("\n");
}

// Print buckets
void printBuckets(struct Node *list) {
  struct Node *cur = list;
  while (cur) {
    printf("%0.2f ", cur->data);
    cur = cur->next;
  }
}

// Driver code
int main(void) {
  float array[lengtharr] = {0.42, 0.32,0.1,0.11,0.19, 0.33, 0.52};

  printf("Initial array: ");
  print(array);
  printf("-------------\n");

  BucketSort(array);
  printf("-------------\n");
  printf("Sorted array: ");
  print(array);
  return 0;
}