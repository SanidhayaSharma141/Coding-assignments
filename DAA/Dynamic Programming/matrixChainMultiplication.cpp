#include <bits/stdc++.h>
using namespace std;

int matrixChainMul(int arr[], int n)
{
    int dp[n][n];
    int j;
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = 0;
    }
    for (int gap = 2; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            j = i + gap;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i] * arr[j] * arr[k]);
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int arr[] = {2, 1, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << matrixChainMul(arr, n) << endl;
    return 0;
}