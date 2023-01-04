

#include <bits/stdc++.h>
using namespace std;
// using Dynamic programming

int longIncSub(int arr[], int n)
{
    int *lis = new int[n];
    int *lds = new int[n];
    lis[0] = 1;
    lds[n - 1] = 1;
    cout << lis[0] << " ";
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if ((arr[j] < arr[i]) && (lis[i] < lis[j] + 1))
            {
                lis[i] = lis[j] + 1;
            }
        }
        cout << lis[i] << " ";
    }
    cout << endl;

    for (int i = n - 2; i >= 0; i--)
    {
        lds[i] = 1;
        for (int j = n - 1; j > i; j--)
        {
            if ((arr[j] < arr[i]) && (lds[i] < lds[j] + 1))
            {
                lds[i] = lds[j] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << lds[i] << " ";
    }
    cout << endl;
    int maxVal = lis[0] + lds[0] - 1;
    for (int i = 1; i < n; i++)
    {
        maxVal = max(maxVal, lis[i] + lds[i] - 1);
        cout << maxVal << " ";
    }
    cout << endl;
    return maxVal;
}

int main()
{
    int arr[] = {80, 60, 30, 40, 20, 10};
    cout << longIncSub(arr, sizeof(arr) / sizeof(arr[0])) << endl;
    return 0;
}

// int longIncSub(int arr[], int n)
// {
//     int *lis = new int[n];
//     int *lds = new int[n];
//     lis[0] = 1;
//     // lds[0] = 1;
//     cout << lis[0] << " ";
//     for (int i = 1; i < n; i++)
//     {
//         lis[i] = 1;
//         for (int j = 0; j < i; j++)
//         {
//             if ((arr[j] < arr[i]) && (lis[i] < lis[j] + 1))
//             {
//                 lis[i] = lis[j] + 1;
//             }
//         }
//         cout << lis[i] << " ";
//     }
//     cout << endl;
//     for (int i = 0; i < n; i++)
//     {
//         lds[i] = 1;
//     }
//     for (int i = n - 2; i >= 0; i--)
//     {
//         // lds[i] = 1;
//         for (int j = n - 1; j > i; j--)
//         {
//             if ((arr[j] < arr[i]) && (lds[i] < lds[j] + 1))
//             {
//                 lds[i] = lds[j] + 1;
//             }
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << lds[i] << " ";
//     }
//     cout << endl;
//     int maxVal = lis[0]+lds[0]-1;
//     for (int i = 1; i < n; i++)
//     {
//         maxVal = max(maxVal, lis[i] + lds[i] - 1);
//         cout << maxVal << " ";
//     }
//     cout << endl;
//     return maxVal;
// }

// int main()
// {
//     int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
//     cout << longIncSub(arr, sizeof(arr) / sizeof(arr[0])) << endl;
//     return 0;
// }

// Another solution
// #include <bits/stdc++.h>
// using namespace std;
// // using Dynamic programming
// void longIS(int lis[], int arr[], int n)
// {
//     cout << lis[0] << " ";
//     for (int i = 1; i < n; i++)
//     {
//         lis[i] = 1;
//         for (int j = 0; j < i; j++)
//         {
//             if (arr[j] < arr[i])
//             {
//                 lis[i] = max(lis[i], lis[j] + 1);
//             }
//         }
//         cout << lis[i] << " ";
//     }
//     cout << endl;
// }
// int longIncSub(int arr[], int n)
// {
//     int lis[n];
//     lis[0] = 1;
//     longIS(lis, arr, n);
//     reverse(arr, arr + n);
//     int lisrev[n];
//     lisrev[0] = 1;
//     longIS(lisrev, arr, n);
//     int maxVal = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         lisrev[i] += lis[i];
//         maxVal = max(maxVal, lisrev[i] - 1);
//     }

//     cout << endl;
//     return maxVal;
// }

// int main()
// {
//     int arr[] = {3, 5, 4, 6, 8, 9, 8, 1, 2, 3, 4};
//     cout << longIncSub(arr, sizeof(arr) / sizeof(arr[0])) << endl;
//     return 0;
// }
