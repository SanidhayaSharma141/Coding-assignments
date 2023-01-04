#include<bits/stdc++.h>
using namespace std; 

//inplace and stable
//preferred for small size arrays
//time complexity:
// worst case: θ(n^2)
// best case: θ(n)
// in general: O(n^2)

void merge(int arr[],int l,int m,int h){
    int n1=m-l+1;
    int n2=h-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=arr[m+1+i];
    }
    int i,j;
    i=j=0;
    int k=l;
    while(i<n1&&j<n2){
        if(L[i]>R[j]){
            arr[k++]=R[j++];
        }
        else{
            arr[k++]=L[i++];
        }
    }
    while(i<n1){
        arr[k++]=L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }
}

void mergeSort(int arr[],int l,int h){
    if(l<h){
        int m=l+((h-l)/2);
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,h);
        merge(arr,l,m,h);
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

    mergeSort(arr, 0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}