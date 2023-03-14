// vegnim
// problem source: https://judge.yosupo.jp/problem/unionfind
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

const int mxn = 2e5;

int n,q,lab[mxn];

void make_set(int u)
{
    lab[u] = -1;
}

int find_set(int u)
{
    if (lab[u] < 0)
        return u;
    return lab[u] = find_set(lab[u]);
}

void union_sets(int u, int v)
{
    int a = find_set(u); int b = find_set(v);
    if (a == b) return;
    if (lab[a] > lab[b]) swap(a, b);
    lab[a] += lab[b];
    lab[b] = a;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
    //freopen("inp.txt","r",stdin);
    cin >> n >> q;
    for (int i=0; i<n; i++){
        make_set(i);
    }
    while (q--){
        int t,u,v; cin >> t >> u >> v;
        if (t == 0){
            union_sets(u, v);
        }
        else{
            cout << (find_set(u) == find_set(v)) << '\n';
        }
    }
    return 0;
}
