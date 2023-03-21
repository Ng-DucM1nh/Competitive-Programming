// vegnim
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

const int maxNode = 100;

struct Trie
{
    struct Node
    {
        int child[26],exist,cnt;
    };
    Node nodes[maxNode];

    int cur;

    Trie()
    {
        cur = 0;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[cur].cnt = 0;
    }

    int nwnode()
    {
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[cur].cnt = 0;
        return cur;
    }

    void add(string s)
    {
        int pos = 0;
        for (int i=0; i<(int)s.length(); i++){
            int c = s[i] - 'a';
            if (nodes[pos].child[c] == -1){
                nodes[pos].child[c] = nwnode();
            }
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }

    bool contain(string s)
    {
        int pos = 0;
        for (int i=0; i<(int)s.length(); i++){
            int c = s[i] - 'a';
            if (nodes[pos].child[c] == -1) return 0;
            pos = nodes[pos].child[c];
        }
        return (nodes[pos].exist > 0);
    }

    bool del_recur(int pos, int id, string s)
    {
        int c = s[id] - 'a';
        if (id < (int)s.length()){
            assert(nodes[pos].child[c] != -1);
            bool childdel = del_recur(nodes[pos].child[c], id+1, s);
            if (childdel)
                nodes[pos].child[c] = -1;
        }
        else{
            nodes[pos].exist--;
        }
        if (pos == 0) return 0;
        nodes[pos].cnt--;
        return (nodes[pos].cnt == 0);
    }

    void del(string s)
    {
        if (!contain(s)) return;
        del_recur(0, 0, s);
    }

    void dfs_print(int pos, string s)
    {
        for (int t=0; t<nodes[pos].exist; t++){
            cout << s<<'\n';
        }
        for (int c=0; c<26; c++){
            if (nodes[pos].child[c] != -1){
                s.pb((char)(c + 'a'));
                dfs_print(nodes[pos].child[c], s);
                s.pop_back();
            }
        }
    }

    void print()
    {
        string s = "";
        int pos = 0;
        dfs_print(pos, s);
    }
};

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
    freopen("inp.txt","r",stdin);
    Trie a;
    a.add("ab");
    a.add("abcdbab");
    a.print(); cout << '\n';
    a.del("ab");
    a.print(); cout << '\n';
    a.del("abduawoiawdiwaoijawdiojwa");
    a.print(); cout << '\n';
    return 0;
}
