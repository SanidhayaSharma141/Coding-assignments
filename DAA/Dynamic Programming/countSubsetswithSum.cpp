#include <bits/stdc++.h>
using namespace std;

int countSub(int arr[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i < sum + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    int arr[] = {2, 7, 3, 66, 11, 15, 17, 18, 19, 4};
    cout << countSub(arr, 10, 21) << endl;
}