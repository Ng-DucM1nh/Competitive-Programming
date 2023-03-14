// vegnim
// https://cses.fi/problemset/task/2195
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

struct Gpoint
{
    ll x,y;
};

using Gvector = Gpoint;

Gvector operator - (Gpoint a, Gpoint b)
{
    return {a.x-b.x, a.y-b.y};
}

ll operator * (Gvector a, Gvector b)
{
    return a.x*b.y - a.y*b.x;
}

const int mxn = 2e5+1;

int n;
Gpoint a[mxn];
vector <Gpoint> hull,v;

bool cw(Gpoint a, Gpoint b, Gpoint c)
{
    Gvector u = b - a; Gvector v = c - b;
    return (u*v > 0);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
    //freopen("inp.txt","r",stdin);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i].x >> a[i].y;
    }
    sort(a+1, a+n+1, [](Gpoint lo, Gpoint hi){
        if (lo.x != hi.x) return (lo.x < hi.x);
        return (lo.y < hi.y);
    });
    for (int i=1; i<=n; i++){
        while ((int)v.size() >= 2 && cw(v[(int)v.size()-2], v.back(), a[i])){
            v.pop_back();
        }
        v.pb(a[i]);
    }
    hull = v;
    hull.pop_back();
    v.clear();
    for (int i=n; i>=1; i--){
        while ((int)v.size() >= 2 && cw(v[(int)v.size()-2], v.back(), a[i])){
            v.pop_back();
        }
        v.pb(a[i]);
    }
    hull.insert(hull.end(), v.begin(), v.end());
    hull.pop_back();
    cout << (int)hull.size()<<'\n';
    for (auto p : hull){
        cout << p.x<<' '<<p.y<<'\n';
    }
    return 0;
}
