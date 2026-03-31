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

#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,tune=native")

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct DSU
{
    vector<int> par;
    vector<int> sz;
    int n, cnt;

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
        n = cnt = _n;
        par.assign(n + 5, 0);
        sz.assign(n + 5, 0);

        MakeSet();
    }

    int Find(int v)
    {
        return par[v] == v ? v : Find(par[v]);
    }

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);

        sz[a] += sz[b];
        par[b] = a;
        cnt--;
    }
};

int const N = 1009;
int const oo = 1e9 + 2;

int n, m, q, v;

DSU dsu;

vector<pair<int, int>> adj[N];
int node[N];

int d[N][N];
int par[N][N];

void Dijkstra(int s, int d[], int par[])
{
    memset(d, 0x3f, (n + 1) * sizeof d);
    d[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[s], s});

    while (!pq.empty())
    {
        int u = pq.top().S;
        int du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto &e : adj[u])
        {
            int v = e.F;
            int w = e.S;

            if (mini(d[v], d[u] + w)) 
            {
                par[v] = u;
                pq.push({d[v], v});
            }
        }
    }
}

bool Check()
{
    int id = dsu.Find(node[1]);
    FOR(i, 1, q) if (dsu.Find(node[i]) != id) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q >> v;
    
    FOR(i, 1, m)
    {
        int u, v, c, x;
        cin >> u >> v >> c >> x;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    FOR(i, 1, q) cin >> node[i];

    FOR(i, 1, q) Dijkstra(node[i], d[node[i]], par[node[i]]);
    dsu = DSU(n);
    
    FOR(i, 1, q)
    {
        vector<int> nodes = {node[i]};
        
        int dist = oo;

        FOR(j, 1, q) for (auto &u : nodes)
        {
            if (dsu.Find(u) == dsu.Find(node[j])) continue;
            if (mini(dist, d[u][node[j]]))
        }
    }    

    return 0;
}