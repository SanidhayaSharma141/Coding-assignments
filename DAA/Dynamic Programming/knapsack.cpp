#include <bits/stdc++.h>
using namespace std;

int knapSack(int val[], int wt[], int n, int W)
{
    int dp[W + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= W; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= W; i++)
    {
        cout << dp[i][0] << " ";
        for (int j = 1; j <= n; j++)
        {
            if (i > wt[j - 1])
            {
                dp[i][j] = max(dp[i][j - 1], val[j - 1] + dp[i - wt[j - 1]][j - 1]);
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[W][n];
}

// int dp[100][100];
// int knapSack(int val[], int wt[], int n, int W)
// {
//     if (W == 0 || n == 0)
//     {
//         return 0;
//     }
//     if (dp[W][n] > 0)
//     {
//         return dp[W][n];
//     }
//     if (W > wt[n - 1])
//     {
//         dp[W][n] = max(knapSack(val, wt, n - 1, W), val[n - 1] + knapSack(val, wt, n - 1, W - wt[n - 1]));
//     }
//     else
//     {
//         dp[W][n] = knapSack(val, wt, n - 1, W);
//     }
//     return dp[W][n];
// }

int main()
{
    int val[] = {10, 40, 30, 50};
    int wt[] = {5, 4, 6, 3};
    int n = 4;
    // for (int i = 0; i < 11; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = knapSack(val, wt, 4, 10);
    cout << "max value: " << ans << endl;
}