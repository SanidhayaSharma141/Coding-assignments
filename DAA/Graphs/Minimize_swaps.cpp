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
    int val, n;
    string s;
    cin >> val;
    while (val)
    {
        val--;
        cin >> s;
        ll ec = 0, oc = 0, zec = 0, zoc = 0;
        ll l = s.size();
        int x;
        int c = 0;
        if (l % 2 == 0)
        {
            x = 0;
        }
        else
        {
            x = 1;
        }
        for (ll i = l - 1; i >= 0; i++)
        {
            if (s[i] == '1')
            {
                if (x == 0)
                {
                    ec++;
                    x = 1;
                }
                else
                {
                    oc++;
                    x = 0;
                }
            }
            else
            {
                if (x == 0)
                {
                    if (s[i - 1] == '1' || s[i + 1] == '1')
                    {
                        zec++;
                    }
                    x = 1;
                }
                else
                {
                    if (s[i - 1] == '1' || s[i + 1] == '1')
                    {
                        zoc++;
                    }
                    x = 0;
                }
            }
        }
        if (abs(ec - oc) % 3 == 1)
        {
            if (zoc % 2 == 0 || zec % 2 == 0)
            {
                cout << 2 << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (abs(ec - oc) % 3 == 2)
        {
            if (ec > oc)
            {
                if ()
            }
        }
        if (abs(ec - oc) % 3 == 0)
        {
            cout << 0 << endl;
            continue;
        }
        // for (ll i = l - 1; i >= 0; i++)
        // {

        // }
    }

    return 0;
}