#include<bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//HoarePartition
int hPartition(int arr[],int l,int h){
    int k=rand();
    int r=k%(h-l+1)+l;
    swap(&arr[l],&arr[r]);
    int pivot=arr[l];
    int i=l-1;
    int j=h+1;
    while(true){
        do{i++;}while(arr[i]<pivot);
        do{j--;}while(arr[j]>pivot);
        if(i>=j) return j;
        swap(&arr[j],&arr[i]);
    }
}

void quickSort(int arr[],int l,int h){
    if(l<h){
        int p=hPartition(arr,l,h);
        quickSort(arr,l,p);
        quickSort(arr,p+1,h);
    }
}


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }

    return 0;
}