#include <bits/stdc++.h>
using namespace std;

int coinChange(int arr[], int val, int n)
{
    int *cc = new int[val + 1];
    cc[0] = 0;
    for (int i = 1; i <= val; i++)
    {
        cc[i] = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (i >= arr[j])
            {
                cc[i] = min(cc[i], 1 + cc[i - arr[j]]);
            }
        }
        // cout << "the min no. of coins for Rs " << i << " are " << cc[i] << endl;
    }
    return cc[val];
}
// int solutionCC(int arr[], int val, int n)
// {
// }
int main()
{
    int coin[] = {1, 3, 4, 6};
    cout << coinChange(coin, 19, sizeof(coin) / sizeof(coin[0])) << endl;
}