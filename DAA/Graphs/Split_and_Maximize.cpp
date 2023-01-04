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
// map<ll,vector<ll>> m;
// map<ll,ll>::iterator it = m.begin();
// m.insert(it, std::pair<ll,ll>(n,p));

int main()
{
    int val, n;
    cin >> val;
    while (val)
    {
        cin >> n;
        long long x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            y =(y+x)%MOD;
        }
        cout <<( y * (y - 1))%MOD << endl;

        val--;
    }

    return 0;
}
