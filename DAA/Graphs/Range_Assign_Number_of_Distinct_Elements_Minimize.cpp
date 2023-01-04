#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pint> vpint;
ll MOD = 998244353;
double eps = 1e-12;
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

bool checkEqual(int arr[], int n, int a, int b)
{
    if (arr[a] == arr[b])
    {
        return 1;
    }
    return 0;
}
int main()
{
    int val, n;
    cin >> val;
    while (val)
    {
        cin >> n;
        int arr[n], arr1[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int c = 0, q = 0;
        int maxval = INT_MIN;
        for (int i = 0; i <= n; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (arr[i] == arr[j])
                {
                    q = 1;
                    if (j - 1 - i > maxval)
                    {
                        c = i - 1 + n - j;
                        maxval = j - 1 - i;
                    }
                }
            }
        }
        if (c <= 2 && q == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        val--;
    }

    return 0;
}