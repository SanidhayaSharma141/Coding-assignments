#include <bits/stdc++.h>
using namespace std;
// using Dynamic programming
 int longIncSub(int arr[], int n)
 {
     int lis[n];
     lis[0] = 1;
     cout << lis[0] << " ";
     for (int i = 1; i < n; i++)
     {
         lis[i] = 1;
         for (int j = 0; j < i; j++)
         {
             if (arr[j] < arr[i])
             {
                 lis[i] = max(lis[i], lis[j] + 1);
             }
         }
         cout << lis[i] << " ";
     }
     cout << endl;
     int res = lis[0];
     for (int i = 1; i < n; i++)
     {
         res = max(res, lis[i]);
     }
     return res;
 }

// using Binary Search
// int bsm(int lis[], int i, int r, int val)
// {
//     int mid;
//     while (r > i)
//     {
//         mid = i + ((r - i) / 2);
//         if (val <= lis[mid])
//         {
//             r = mid;
//         }
//         else
//         {
//             i = mid + 1;
//         }
//     }
//     return r;
// }
// int LongIncSub(int arr[], int n)
// {
//     int lis[n];
//     lis[0] = arr[0];
//     int len = 1;
//     int p;
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] > arr[len - 1])
//         {
//             lis[len++] = arr[i];
//         }
//         else
//         {
//             p = bsm(lis, 0, len - 1, arr[i]);
//             lis[p] = arr[i];
//         }
//     }
//     return len;
// }
int main()
{
    int arr[] = {3, 5, 4, 6, 8, 9, 1, 2, 3, 4};
    cout << longIncSub(arr, sizeof(arr) / sizeof(arr[0])) << endl;
    return 0;
}
