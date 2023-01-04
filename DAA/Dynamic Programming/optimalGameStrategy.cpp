#include <bits/stdc++.h>
using namespace std;

/* //recursive solution-1
int optimalGameSol(int arr[], int i, int j, int sum)
{
    if (j == i + 1)
    {
        return max(arr[i], arr[j]);
    }
    return max(sum - optimalGameSol(arr, i + 1, j, sum - arr[i]), sum - optimalGameSol(arr, i, j - 1, sum - arr[j]));
}*/
/* //recursive solution-2
int optimalGameSol(int arr[], int i, int j)
{
    if (i + 1 == j)
    {
        return max(arr[i], arr[j]);
    }
    return max(arr[i] + min(optimalGameSol(arr, i + 1, j - 1), optimalGameSol(arr, i + 2, j)), arr[j] + min(optimalGameSol(arr, i + 1, j - 1), optimalGameSol(arr, i, j - 2)));
}
 */

// Dynamic Programming solution
int optimalGameSol(int arr[], int n)
{
    int dp[n][n];
    int j;
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = max(arr[i], arr[i + 1]);
    }
    for (int gap = 3; gap < n; gap = gap + 2)
    {
        for (int i = 0; i + gap < n; i++)
        {
            j = i + gap;
            dp[i][j] = max((arr[i] + min(dp[i + 1][j - 1], dp[i + 2][j])), (arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2])));
        }
    }
    return dp[0][n - 1];
}
int main()
{
    int arr[] = {20, 4, 77, 23, 5, 7};
    cout << optimalGameSol(arr, 6);
}