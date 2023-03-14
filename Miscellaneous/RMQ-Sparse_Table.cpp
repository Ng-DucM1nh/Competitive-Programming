// vegnim
// problem source: https://www.spoj.com/problems/RMQSQ/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setpre(n) fixed << setprecision(n)
#define task ""

const int mxn = 1e5;

int n,a[mxn],spt[mxn][18],lg[mxn],q;

void init_spt()
{
    for (int i=0; i<n; i++){
        spt[i][0] = a[i];
    }
    for (int j=1; (1 << j) < n; j++){
        for (int i=0; i+(1 << j)-1 < n; i++){
            spt[i][j] = min(spt[i][j-1], spt[i+(1 << (j-1))][j-1]);
        }
    }
}

void init_lg()
{
    lg[1] = 0;
    for (int i=2; i<=n; i++){
        lg[i] = lg[i/2] + 1;
    }
}

int rmq(int i, int j)
{
    int pw = lg[j-i+1];
    return min(spt[i][pw], spt[j-(1<<pw)+1][pw]);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
    //freopen("inp.txt","r",stdin);
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> q;
    init_spt(); init_lg();
    while (q--){
        int i,j; cin >> i >> j;
        cout << rmq(i,j) << '\n';
    }
    return 0;
}

