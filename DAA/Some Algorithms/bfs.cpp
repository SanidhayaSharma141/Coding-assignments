#include <bits/stdc++.h>
using namespace std;

void bfs(int **arr, int n, bool visited[])
{
    int que[n];
    que[0] = 0;
    int x = n;
    int p = 1;
    int val = 0;
    while (x != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[val][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                que[p++] = i;
            }
        }
        cout << que[val++] << " ";
        x--;
    }
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
            bfs(arr, n, visited);
            cout << endl;
        }
    }
}