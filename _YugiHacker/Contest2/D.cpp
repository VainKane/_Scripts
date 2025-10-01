#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MK(i) (1ll << (i))
#define F first
#define S second
#define name "backup"

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct DSU
{
    vector<int> par;
    vector<int> sz;
    int n;

    void MakeSet()
    {
        FOR(i, 1, n)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }

    DSU(int _n = 0)
    {
        n = _n;
        par.assign(n + 5, 0);
        sz.assign(n + 5, 0);
        MakeSet();
    }

    int Find(int v)
    {
        if (par[v] == v) return v;
        return par[v] = Find(par[v]);
    }

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
    }
};

struct Query
{
    int type, u, v;
};

int const N = 1e5 + 5;
int const oo = 1e9;
int const LOG = 17;

int n, q;
vector<pair<int, int>> adj[N];

Query qr[N];

int h[N];
int upPar[N][20];
int upMin[N][20];
DSU dsu;

int res[N];

void DFS(int u, int p)
{
    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;
        h[v] = h[u] + 1;
        upPar[v][0] = u;
        upMin[v][0] = w;

        FOR(i, 1, LOG) 
        {
            upPar[v][i] = upPar[upPar[v][i - 1]][i - 1];
            upMin[v][i] = min(upMin[v][i - 1], upMin[v + MK(i - 1)][i - 1]);
        }
        DFS(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];

    for (int tmp = delta; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp & -tmp);
        u = upPar[u][i];
    }

    if (u == v) return u;

    FORD(i, LOG, 0) if (upPar[u][i] != upPar[v][i])
    {
        u = upPar[u][i];
        v = upPar[v][i];
    }

    return upPar[u][0];
}

int GetMin(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];

    if (u == v) return 0;

    int res = oo;
    for (int tmp = delta; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp & -tmp);
        mini(res, upMin[u][i]);
        u = upPar[u][i];
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    FOR(i, 1, q) 
    {
        int type; cin >> type;
        qr[i].type = type;
        if (type == 1) cin >> qr[i].u >> qr[i].v;
        else cin >> qr[i].u;
    }
    
    memset(upMin, 0x3f, sizeof upMin);
    dsu = DSU(n);
    DFS(1, -1);
    
    FORD(i, q, 1)
        if (qr[i].type == 1)
        {
            int u = qr[i].u;
            int v = qr[i].v;

            int p = LCA(u, v);
            if (dsu.Find(u) == dsu.Find(v)) res[i] = min(GetMin(u, p), GetMin(v, p));
            else res[i] = -1;
        }
        else for (auto &e : adj[qr[i].u]) dsu.Union(qr[i].u, e.F);

    FOR(i, 1, q) if (qr[i].type == 1) cout << res[i] << '\n';

    return 0;
}