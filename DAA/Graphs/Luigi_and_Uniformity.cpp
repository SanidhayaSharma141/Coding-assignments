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

int gcd(int a, int b) 
{  
    if (b == 0)  
        return a;  
    return gcd(b, a % b);   
       
}  

int main() {
    int val,n;
    cin>>val;
    while(val){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        // int count=0;
        // int maxval=INT_MIN,maxv=0;
        // for(int i=0;i<n-1;i++){
        //     if(arr[i]==arr[i+1]){
        //         count++;
        //     }
        //     else{
        //         if(maxval<count){
        //             maxv=arr[i];
        //             maxval=count;
        //         }
        //         count=0;
        //     }
        // }
        int val1=gcd()
        cout<<n-maxval<<endl;
        val--;
    }
	
	return 0;
}