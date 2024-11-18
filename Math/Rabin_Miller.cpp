// https://www.spoj.com/problems/PON/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setpre(n) fixed << setprecision(n)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define task ""

ull n;

ull binmul(ull a, ull b, ull mod)
{
    a %= mod;
    ull ans = 0;
    while (b){
        if (b&1) ans = (ans + a) % mod;
        a = a * 2 % mod;
        b >>= 1;
    }
    return ans;
}

ull binpow(ull a, ull b, ull mod)
{
    a %= mod;
    ull ans = 1;
    while (b){
        if (b&1) ans = binmul(ans, a, mod);
        b >>= 1;
        a = binmul(a, a, mod);
    }
    return ans;
}

bool mod_check(ull n, ull a, ull k, ull m)
{
    ull x = binpow(a, m, n);
    if (x == 1 || x == n-1) return 1;
    for (int p=1; p<k; p++){
        x = binmul(x, x, n);
        if (x == n-1) return 1;
    }
    return 0;
}

bool RabinMiller(ull n)
{
    if (n == 2) return 1;
    ull k = 0, m = n-1;
    while ((m&1) == 0){
        k++;
        m >>= 1;
    }
    vector <int> checkSet = {2,3,5,7,11,13,17,19,23,29,31,37};
    for (auto a : checkSet){
        if (a == n) return 1;
        if (!mod_check(n, a, k, m)) return 0;
    }
    return 1;
}

void solve()
{
    cin >> n;
    cout << (RabinMiller(n) ? "YES" : "NO");
}

signed main()
{
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr);
    int TEST; cin >> TEST;
    while (TEST--){
        solve();
        cout << '\n';
    }
    return 0;
}
