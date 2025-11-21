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
    }

    int Find(int v)
    {
        if (par[v] == v) return v;
        return par[v] = Find(par[v]);
    }

    bool Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return false;

        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;

        return true;
    }
};

struct Edge
{
    int u, v, w;

    bool operator < (Edge const other) const
    {
        return w < other.w;
    }
};

int const N = 5e4 + 5;

int n, m;
Edge edges[N];

DSU dsu;

long long Kruskal(int id)
{
    long long res = 0;
    dsu.MakeSet();

    FOR(i, 1, m) if (i != id && dsu.Union(edges[i].u, edges[i].v)) res += edges[i].w;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    sort(edges + 1, edges + m + 1);
    dsu = DSU(n);

    long long cost = Kruskal(0);

    vector<pair<int, int>> res;
    FOR(i, 1, m) if (Kruskal(i) == cost)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        res.push_back({min(u, v), max(u, v)});
    }

    sort(all(res));

    cout << sz(res) << '\n';
    for (auto &p : res) cout << p.F << ' ' << p.S << '\n';

    return 0;
}