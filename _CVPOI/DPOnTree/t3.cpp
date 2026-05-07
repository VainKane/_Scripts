#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
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
long long const oo = 1e18;

int n, m;

int a[N], node[N];
vector<pair<int, int>> adj[N];
bool mark[N];

int up[2 * N][20];
int pos[N];
int timer = 0;

long long d[N];

bool lol[N];
long long c[N];

bool cmp(int u, int v)
{
    return pos[u] < pos[v];
}

void DFSPrepare(int u, int p)
{
    up[++timer][0] = u;
    pos[u] = timer;

    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;

        d[v] = d[u] + w;
        DFSPrepare(v, u);
        up[++timer][0] = u;
    }
}

void DFS(int u, int p)
{
    lol[u] = mark[u];
    c[u] = 0;

    for (auto &e : adj[u])
    {
        int v = e.F;
        if (v == p) continue;

        DFS(v, u);

        lol[u] |= lol[v];
        c[u] += a[u] * lol[v];
        c[u] += c[v];
    }
}

void Build()
{
    FOR(j, 1, 31 - __builtin_clz(timer)) FOR(i, 1, timer - MK(j) + 1)
        up[i][j] = min(up[i][j - 1], up[i + MK(j - 1)][j - 1], cmp);
}

int LCA(int u, int v)
{
    u = pos[u], v = pos[v];
    if (u > v) swap(u, v);

    int k = 31 - __builtin_clz(v - u + 1);
    return min(up[u][k], up[v - MK(k) + 1][k], cmp);
}

long long Dist(int u, int v)
{
    return d[u] + d[v] - 2 * d[LCA(u, v)];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m)
    {
        cin >> node[i];
        mark[node[i]] = true;
    }

    DFSPrepare(1, -1);
    Build();

    long long res = oo;

    FOR(u, 1, n)
    {
        vector<int> nodes = {u};
        FOR(i, 1, m) nodes.push_back(node[i]);
        nodes.push_back(u);

        long long cost = 0;
        REP(i, sz(nodes) - 1) cost += Dist(nodes[i], nodes[i + 1]);

        DFS(u, -1);
        for (auto &e : adj[u]) cost += c[e.F];

        mini(res, cost);
    }

    cout << res;

    return 0;
}