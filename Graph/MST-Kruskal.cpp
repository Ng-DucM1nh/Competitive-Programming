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
    int u,v,w;
};

const int mxn = 1e4+1, mxm = 1e5+1;

int n,m,lab[mxn];
edge e[mxm];

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
    if (lab[a] > lab[b]) swap(a,b);
    lab[a] += lab[b];
    lab[b] = a;
}

ll kruskal()
{
    ll mstw = 0;
    for (int i=1; i<=n; i++){
        make_set(i);
    }
    sort(e+1, e+m+1, [&](edge lo, edge hi){
        return (lo.w < hi.w);
    });
    int cnt = 0;
    for (int i=1; i<=m; i++){
        int u,v,w;
        u = e[i].u; v = e[i].v; w = e[i].w;
        if (find_set(u) == find_set(v)) continue;
        union_sets(u, v);
        mstw += w;
        cnt++;
        if (cnt == n-1) break;
    }
    return mstw;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
    //freopen("inp.txt","r",stdin);
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    cout << kruskal();
    return 0;
}

