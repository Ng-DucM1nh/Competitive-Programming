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
inline bool operator > (edge lo, edge hi)
{
    return (lo.w > hi.w);
}

const int mxn = 1e4+1;

int n,m;
vector <edge> adj[mxn];
priority_queue <edge, vector<edge>, greater<edge> > pq;
bool vis[mxn];

ll prim(int root)
{
    ll mstw = 0;
    pq.push({root, 0});
    while (!pq.empty()){
        int u,w;
        u = pq.top().v; w = pq.top().w;
        pq.pop();
        if (vis[u]) continue;
        mstw += w;
        vis[u] = 1;
        for (auto p : adj[u]) if (!vis[p.v]){
            pq.push({p.v, p.w});
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

