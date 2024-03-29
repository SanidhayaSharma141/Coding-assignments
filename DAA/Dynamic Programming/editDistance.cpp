#include <bits/stdc++.h>
using namespace std;

int editDistance(string s1, int n, string s2, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n][m];
}

int main()
{
    string s1 = "Saturday";
    string s2 = "Sunday";
    cout << editDistance(s1, s1.size(), s2, s2.size());
}