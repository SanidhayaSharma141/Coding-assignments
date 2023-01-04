#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    int *dp = new int[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (j + arr[j] >= i && dp[j] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[j] + 1);
                // break;
            }
        }
        cout << "Minimum Jumps required for " << i << "th position: " << dp[i] << endl;
    }
    return dp[n - 1];
}
int main()
{
    int arr[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Jumps required are: " << minJumps(arr, n) << endl;
}