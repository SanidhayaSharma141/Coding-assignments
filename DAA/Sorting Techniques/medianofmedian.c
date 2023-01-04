#include<stdio.h>
#include<stdlib.h>


// int median(int arr[],int l,int h){
//     int jk=0;
//     if((h-l+1)%5!=0){
//         jk=(h);
//     }
//     int arr1[13/5];
//     int k=l;
//     int i=0;
//     int ct=0;
//     if(l<h){
//       while(h-l-k>=5){
//         arr1[i++]=median(arr,k,k+4);
//         k=k+5;
//       }  
//       ct=i+1;
//       arr1[i++]=median(arr,k,h);

//     }
//     int x=arr1[(ct/2)+1];
//     return x;
// }
void insertionSort(int arr[],int l,int h) {
  for (int i = l+1; i <=h; i++) {
    int key = arr[i];
    int j = i - 1;
    while (key < arr[j] && j >= l) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
    // for(int i = 0; i <=27; i++){
    //     printf("%d ",arr[i]);
    // }
}

int median5(int arr[],int l,int h){
    insertionSort(arr,l,h);
    int k=h-l+1;
    int n=(k+1)/2;
    return arr[l+n-1];
}
int median(int arr[],int n){
    int no,i;
    if(n<=5){
        return(arr[((n+1)/2)-1]);
    }
    if(n%5==0){
        no=n/5;
    }
    else{
        no=(n/5)+1;
    }
    int arr1[no];
    int l=0;
    // printf("%d\n",no);
    for(i=0,l=0;i<no-1;i++){
        arr1[i]=median5(arr,l,l+4);
        l=l+5;
    }
    arr1[no-1]=median5(arr,l,n-1);
    // printf("%d %d %d %d %d %d\n", arr1[0],arr1[1],arr1[2],arr1[3],arr1[4],arr1[5]);
    
    return median(arr1,no);
}


// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int l, int h) {
    int i=l;
    int j=h;
  // select the rightmost element as pivot
  int pivot=median(array);
  do{
  do{i++;}while(array[i]<=pivot);
  do{j--;}while(array[j]>pivot);
  if(i<j){
    swap(array[i],array[j]);
  }}while(i<j);
  swap(,A[j])
}

// void quickSort(int array[], int low, int high) {
//   if (low < high) {

//     // find the pivot element such that
//     // elements smaller than pivot are on left of pivot
//     // elements greater than pivot are on right of pivot
//     int pi = partition(array, low, high);

//     // recursive call on the left of pivot
//     quickSort(array, low, pi - 1);

//     // recursive call on the right of pivot
//     quickSort(array, pi + 1, high);
//   }
// }

// function to print array elements
// void printArray(int array[], int size) {
//     int i;
//   for ( i = 0; i < size; ++i) {
//     printf("%d  ", array[i]);
//   }
//   printf("\n");
// }

// main function

int main(void){
    int arr[28]={4,2,3,1,8,5,9,99,70,103,102,101,104,101,109,107,178,176,204,298,166,543,578,4,5,204,298,345};
    printf("%d",median(arr,28));
    return 0;
}