// https://codeforces.com/contest/222/problem/E
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

using matrix = vector <vector <int> >;

const int MOD = 1e9+7;

int code[(int)'z'+5],m,k,ans;
matrix a;
ll n;

void prep()
{
    int val = 0;
    for (int i='a'; i<='z'; i++){
        code[i] = val++;
    }
    for (int i='A'; i<='Z'; i++){
        code[i] = val++;
    }
}

void show(const matrix &t)
{
    for (int i=0; i<sz(t); i++){
        for (int j=0; j<sz(t[i]); j++){
            cout << t[i][j]<<' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

matrix operator*(const matrix &a, const matrix &b)
{
    assert(sz(a[0]) == sz(b));
    int m = sz(a), n = sz(b), p = sz(b[0]);
    matrix ans(m, vector <int> (p));
    for (int i=0; i<m; i++){
        for (int j=0; j<p; j++){
            for (int k=0; k<n; k++){
                ans[i][j] = (ans[i][j] + (ll)a[i][k] * b[k][j] % MOD) % MOD;
            }
        }
    }
    return ans;
}

matrix iden_matrix(int n)
{
    // create identity matrix with size n*n
    matrix ans(m, vector <int> (n));
    for (int i=0; i<n; i++){
        ans[i][i] = 1;
    }
    return ans;
}

matrix matrix_pw(const matrix &a, ll p)
{
    matrix ans = iden_matrix(sz(a));
    matrix base = a;
    while (p){
        if (p&1) ans = ans * base;
        base = base * base;
        p >>= 1;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr);
    // freopen("inp.txt","r",stdin);
    prep();
    cin >> n >> m >> k;
    a.assign(m, vector <int> (m));
    for (int i=0; i<m; i++){
        for (int j=0; j<m; j++){
            a[i][j] = 1;
        }
    }
    while (k--){
        char x,y; cin >> x >> y;
        a[code[x]][code[y]] = 0;
    }
    matrix dp(1, vector <int> (m, 1)); // dp[1]
    a = matrix_pw(a, n-1);
    dp = dp * a;
    ans = 0;
    for (int i=0; i<m; i++){
        ans = ((ll)ans + dp[0][i]) % MOD;
    }
    cout << ans;
    // cout << "\nFINISHED\n";
    return 0;
}
