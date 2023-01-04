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

int main()
{
    int val, n, k, l;
    cin >> val;
    while (val)
    {
        int p;
        cin >> n >> k >> l;
        int x = 0;
        if (l + k > n)
        {
            p = l + k - n;
            x = (l - p) * (k - p);
        }
        else if (l + k == n)
        {
            x = l * k;
        }
        else
        {
            p = n - l - k;
            x = (l * k) + ((k + l) * p) + (p * (p - 1));
        }
        int y = ((n - max(l, k)) * (n - max(l, k) - 1)) + (max(l, k) - min(l, k)) * (n - max(l, k));
        cout << max(x, y) << endl;

        val--;
    }

    return 0;
}