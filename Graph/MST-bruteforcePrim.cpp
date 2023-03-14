// vegnim
// problem source: https://www.spoj.com/problems/MST/
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

struct edge
{
    int v,w;
};

const int mxn = 1e4+1;
const ll INF = 1e17;

int n,m;
vector <edge> adj[mxn];
ll dis[mxn];
bool vis[mxn];

ll prim(int root)
{
    ll mstw = 0;
    for (int i=1; i<=n; i++){
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[root] = 0;
    for (int i=1; i<=n; i++){
        ll mndis = INF+1; int u;
        for (int j=1; j<=n; j++) if (!vis[j]){
            if (mndis > dis[j]){
                mndis = dis[j];
                u = j;
            }
        }
        vis[u] = 1;
        mstw += dis[u];
        for (auto p : adj[u]) if (!vis[p.v]){
            dis[p.v] = min(dis[p.v], 1LL*p.w);
        }
    }
    return mstw;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
    //freopen("inp.txt","r",stdin);
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    cout << prim(1);
    return 0;
}

