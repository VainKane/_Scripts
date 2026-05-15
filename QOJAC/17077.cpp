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

struct Edge
{
    int u, v, w;

    void Input()
    {
        cin >> u >> v >> w;
    }
};

int const N = 1509;
int const M = 5009;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n, m;

vector<int> adj[N];
vector<int> dagAdj[N];
Edge edges[M];

int d[N];

vector<int> topo;
int deg[N];

int f[N], g[N];
int res[M];

void Dijkstra(int s)
{
    memset(d, 0x3f, sizeof d);
    d[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[s], s});

    while (!pq.empty())
    {
        int u = pq.top().S;
        int du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto &id : adj[u])
        {
            int v = edges[id].v;
            int w = edges[id].w;

            if (mini(d[v], d[u] + w)) pq.push({d[v], v});
        }
    }
}

void BFS()
{
    queue<int> q;
    FOR(u, 1, n) if (!deg[u]) q.push(u), f[u] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        topo.push_back(u);

        for (auto &id : dagAdj[u])
        {
            int v = edges[id].v;
            if (!--deg[v]) q.push(v);
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
        edges[i].Input();
        adj[edges[i].u].push_back(i);
    }

    FOR(s, 1, m)
    {
        FOR(u, 1, n) dagAdj[u].clear(), deg[u] = 0;
        topo.clear();

        Dijkstra(s);

        FOR(i, 1, m)
        {
            int u = edges[i].u, v = edges[i].v;
            if (d[u] + edges[i].w == d[v]) dagAdj[u].push_back(i), deg[v]++;
        }

        BFS();

        FOR(u, 1, n) g[u] = dagAdj[u].empty();

        for (auto &u : topo) for (auto &id : dagAdj[u])
        {
            int v = edges[id].v;
            Add(f[v], f[u] + 1);
        }

        FORD(i, sz(topo) - 1, 0)
        {
            int u = topo[i];

            for (auto &id : dagAdj[u])
            {
                int v = edges[id].v;
                Add(g[u], g[v] + 1);
            }
        }

        for (auto &u : topo) for (auto &id : dagAdj[u])
            res[id] = (res[id] + 1LL * f[u] * g[edges[id].v]) % MOD;
    }

    FOR(i, 1, m) cout << res[i] << '\n';

    return 0;
}