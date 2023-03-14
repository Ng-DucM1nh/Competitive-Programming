// vegnim
// https://oj.vnoi.info/problem/latgach4
#include <bits/stdc++.h>
using namespace std;
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
#define task ""

const int MOD = 111539786;

using Mttype = ll;

struct Matrix
{
    vector <vector <Mttype> > data;

    Matrix() = default;

    Matrix(int r, int c)
    {
        data.resize(r, vector <Mttype> (c));
    }

    Matrix(vector <vector <Mttype> > d)
    {
        data = d;
    }

    int row()
    {
        return data.size();
    }

    int col()
    {
        return (row() == 0) ? 0 : data[0].size();
    }

    Matrix identity(int n)
    {
        Matrix ans(n,n);
        while (n--) ans.data[n][n] = 1;
        return ans;
    }

    Matrix operator * (Matrix b)
    {
        assert(col() == b.row());
        Matrix ans(row(), b.col());
        for (int i=0; i<row(); i++){
            for (int j=0; j<b.col(); j++){
                for (int k=0; k<col(); k++){
                    ans.data[i][j] = (ans.data[i][j] + data[i][k] * b.data[k][j] % MOD) % MOD;
                }
            }
        }
        return ans;
    }

    Matrix exp(int p)
    {
        assert(row() == col());
        Matrix base(data);
        Matrix ans = identity(row());
        for (; p > 0; p/=2, base = base*base){
            if (p&1) ans = ans * base;
        }
        return ans;
    }
};

void solve()
{
    int n; cin >> n;
    Matrix H({
        {0, 1},
        {1, 1}
    });
    Matrix R1({
        (vector <Mttype> ){1},
        (vector <Mttype> ){1}
    });
    H = H.exp(n-1);
    Matrix ans = H * R1;
    cout << ans.data.back().back();
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--){
        solve();
        cout << '\n';
    }
    return 0;
}
