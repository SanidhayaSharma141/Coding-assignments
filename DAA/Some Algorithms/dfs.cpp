#include <bits/stdc++.h>
using namespace std;

void dfs(int val, bool visited[], int **arr, int n)
{
    visited[val] = true;
    for (int i = 0; i < n; i++)
    {
        if (arr[val][i] == 1 && visited[i] != 1)
        {
            dfs(i, visited, arr, n);
        }
    }
    cout << val << " ";
}
int main(void)
{
    int n;
    cin >> n;
    int **arr;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, visited, arr, n);
            cout << endl;
        }
    }
}