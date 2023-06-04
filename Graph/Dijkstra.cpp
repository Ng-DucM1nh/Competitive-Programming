// vegnim
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setpre(n) fixed << setprecision(n)
#define sz(x) (int)x.size()
#define task "DIJKSTRA"

const ll INF = 1e18;
const int maxN = 1e5+5;

int n,m;
vector <pii> adj[maxN];
ll d[maxN];
priority_queue <pll, vector<pll>, greater<pll> > pq;

void dijkstra()
{
    fill(d+1, d+n+1, INF);
    d[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()){
        ll r = pq.top().fi; int u = pq.top().se;
        pq.pop();
        if (r > d[u]) continue;
        for (auto e : adj[u]){
            int v = e.fi, w = e.se;
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
    //freopen("inp.txt","r",stdin);
    cin >> n >> m;
    while (m--){
        int u,v,w; cin >> u >> v >> w;
        adj[u].pb({v, w});
    }
    dijkstra();
    if (d[n] == INF)
        cout << -1;
    else
        cout << d[n];
    return 0;
}
