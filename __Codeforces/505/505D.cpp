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
vector<int> dagAdj[N];

int ccId[N];

int in[N], low[N];
int timer = 0, cc = 0;

stack<int> st;
vector<int> scc[N];

int inDeg[N];
int f[N], g[N];

vector<int> topo;
int h[N];

void Tarjan(int u)
{
    low[u] = in[u] = ++timer;
    st.push(u);

    for (auto &v : adj[u])
    {
        if (ccId[v]) continue;
        if (in[v]) mini(low[u], in[v]);
        else
        {
            Tarjan(v);
            mini(low[u], low[v]);
        }
    }

    if (low[u] == in[u])
    {
        int v = 0;
        cc++;

        while (v != u)
        {
            v = st.top(); st.pop();
            ccId[v] = cc;
        }
    }
}

void BFS()
{
    queue<int> q;
    FOR(u, 1, cc) if (!inDeg[u]) q.push(u);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        topo.push_back(u);

        for (auto &v : dagAdj[u]) if (!--inDeg[v]) 
        {
            h[v] = h[u] + 1;
            q.push(v);
        }
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
    }

    FOR(u, 1, n) if (!in[u]) Tarjan(u);

    FOR(u, 1, n) scc[ccId[u]].push_back(u);
    FOR(i, 1, n) for (auto &j : adj[i])
    {
        int u = ccId[i];
        int v = ccId[j];

        if (u == v) continue;
        dagAdj[u].push_back(v);
        inDeg[v]++;
    }

    FOR(u, 1, cc)
    {
        sort(all(dagAdj[u]));
        dagAdj[u].erase(unique(all(dagAdj[u])), dagAdj[u].end());
    }

    BFS();

    for (auto &u : topo) for (auto &v : dagAdj[u])
    {
        if (maxi(f[v], h[u])) g[v] = 1;
        else if (f[v] == h[u]) g[v]++;
    }

    int res = 0;

    FOR(u, 1, cc) 
    {
        if (sz(scc[u]) > 1) res += sz(scc[u]);
        res += g[u];
    }

    cout << res;

    return 0;
}