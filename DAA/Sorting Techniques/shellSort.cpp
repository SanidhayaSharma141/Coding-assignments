#include<bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void shellSort(int arr[],int n){
    int gap,i,j;
    for(gap=n/2;gap>=1;gap/=2){
        for(i=gap;i<n;i++){
            int temp=arr[i];
            j=i-gap;
            while(j>=0 && arr[j]>temp){
                arr[j+gap]=arr[j];
                j=j-gap;
            }
            arr[j+gap]=temp;
        }
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

    shellSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}