#include <bits/stdc++.h>
using namespace std;

int changeCombination(int coin[], int val, int n)
{
    int dp[val + 1][n + 1];
    for (int i = 0; i < val + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= val; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (i >= coin[j - 1])
            {
                dp[i][j] += dp[i - coin[j - 1]][j];
            }
        }
        // cout << "no.of combinations for cost " << i << " is " << dp[i][n] << endl;
    }
    return dp[val][n];
}

// int changeCombination(int coin[], int val, int n)
// {
//     int dp[val + 1];
//     memset(dp, 0, sizeof(dp));
//     dp[0] = 1;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = coin[i]; j <= val; j++)
//         {
//             dp[j] += dp[j - coin[i]];
//         }
//     }
//     return dp[val];
// }

int main()
{
    int coin[] = {3, 4, 7};
    int n = sizeof(coin) / sizeof(coin[0]);
    cout << "total no. of combinations are: " << changeCombination(coin, 1, n) << endl;
}