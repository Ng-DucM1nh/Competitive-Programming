// vegnim
// https://vn.spoj.com/problems/LCA/
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

const int maxN = 1e3+5;

int n,q,h[maxN],up[maxN][15];
vector <int> adj[maxN];

void dfs(int u)
{
    for (auto v : adj[u]) if (v != up[u][0]){
        h[v] = h[u] + 1;
        up[v][0] = u;
        for (int i=1; i<15; i++){
            up[v][i] = up[up[v][i-1]][i-1];
        }
        dfs(v);
    }
}

int lca(int u, int v)
{
    if (h[u] < h[v]) swap(u,v);
    for (int bit=0; (1 << bit) <= h[u]-h[v]; bit++){
        if ((h[u] - h[v]) >> bit & 1)
            u = up[u][bit];
    }
    if (u == v) return u;
    for (int i=14; i>=0; i--){
        if (up[u][i] == up[v][i]) continue;
        u = up[u][i];
        v = up[v][i];
    }
    return up[u][0];
}

void solve()
{
    cin >> n;
    memset(h, 0, sizeof(h));
    for (int u=1; u<=n; u++){
        adj[u].clear();
    }
    for (int u=1; u<=n; u++){
        int m; cin >> m;
        while (m--){
            int v; cin >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
    dfs(1);
    cin >> q;
    while (q--){
        int u,v; cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for (int i=1; i<=t; i++){
        cout << "Case "<<i<<":\n";
        solve();
        cout << '\n';
    }
    return 0;
}
