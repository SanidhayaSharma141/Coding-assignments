#include<bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[],int n){
    int i,j,k;
    for(int i=0;i<n-1;i++){
        k=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[k]){
                k=j;
            }
        }
        swap(&arr[k],&arr[i]);

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

    selectionSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}