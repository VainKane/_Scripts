#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;

int n, m;
vector<int> adj[N];

int in[N], low[N];
int cnt = 0;

int ccId[N], cutId[N];
int cc = 0, cut = 0;

stack<int> st;

void DFS(int u, int id)
{
    cutId[u] = id;
    for (auto &v : adj[u]) if (!cutId[v]) DFS(v, id);
}

void Tarjan(int u, int p)
{
    low[u] = in[u] = ++cnt;
    int child = (p != -1);
    st.push(u);

    for (auto &v : adj[u])
    {
        if (ccId[v] || v == p) continue;
        if (in[v]) mini(low[u], in[v]);
        else
        {
            Tarjan(v, u);
            mini(low[u], low[v]);

            child += low[v] >= in[u];
        } 
    }

    if (low[u] == in[u])
    {
        int v = 0;
        cc++;

        while (v != u)
        {
            v = st.top();
            st.pop();
            ccId[v] = cc;
        }
    }

    if (child >= 2) 
    {
        cutId[u] = -1;
        for (auto &v : adj[u]) if (!cutId[v]) DFS(v, ++cut);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Tarjan(1, -1);

    int q; cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        if (ccId[u] != ccId[v]) cout << "4 1\n";
        else if (cutId[u] != cutId[v]) cout << "3 0\n";
        else cout << "2 0\n";
    }

    FOR(u, 1, n) cout << cutId[u] << ' ';

    return 0;
}