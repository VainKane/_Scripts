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
int const LOG = 18;
int const BK = 314;
int const GR = N / BK + 5;
int const oo = 1e9;
int bkId[N], bkL[GR], bkR[GR];

int n, q;
vector<int> adj[N];
pair<int, int> qr[N];

int up[N][20];
int h[N], d[N];

int ds[1009][1009];

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        up[v][0] = u;

        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];
        DFS(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    FORD(i, LOG, 0) if (h[up[u][i]] >= h[v]) u = up[u][i];
    if (u == v) return u;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

int Dist(int u, int v)
{
    if (u <= 1000 && v <= 1000 && ds[u][v] != -1) return ds[u][v];
    return h[u] + h[v] - 2 * h[LCA(u, v)];
}

void BFS(int l, int r)
{
    if (l > r) return;

    memset(d, 0x3f, sizeof d);
    queue<int> q;
    
    FOR(i, l, r) if (qr[i].F == 1)
    {
        q.push(qr[i].S);
        d[qr[i].S] = 0;
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : adj[u]) if (d[v] > oo)
        {
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

void Init()
{
    FOR(i, 1, q)
    {
        int id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
    }

    FOR(u, 1, 1000) FOR(v, u, 1000) ds[u][v] = ds[v][u] = Dist(u, v); 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(i, 1, q) cin >> qr[i].F >> qr[i].S;

    DFS(1, -1);

    memset(d, 0x3f, sizeof d);
    memset(ds, -1, sizeof ds);
    h[0] = -1;

    Init();

    FOR(id, 1, bkId[q])
    {
        BFS(1, bkR[id - 1]);
        vector<int> nodes = {1};

        FOR(i, bkL[id], bkR[id])
        {
            int u = qr[i].S;
            if (qr[i].F == 1) nodes.push_back(u);
            else
            {
                int res = d[u];
                for (auto &v : nodes) mini(res, Dist(u, v));
                cout << res << '\n';
            }
        }
    }

    return 0;
}