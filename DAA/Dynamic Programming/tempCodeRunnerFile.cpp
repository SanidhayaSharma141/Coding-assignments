dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            