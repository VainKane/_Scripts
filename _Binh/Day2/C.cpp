#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 3e5 + 5;

int n;
vector<int> adj[N];

int par[N];
int f1[N], f2[N], f3[N];
int f[N], fPar[N], g[N];

void DFSPrepare(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        DFSPrepare(v, u);

        if (f1[v] + 1 > f1[u]) 
        {
            f3[u] = f2[u];
            f2[u] = f1[u];
            f1[u] = f1[v] + 1;
        }
        else if (f1[v] + 1 > f2[u])
        {
            f3[u] = f2[u];
            f2[u] = f1[v] + 1;
        }
        else maxi(f3[u], f1[v] + 1);

        maxi(f[u], max(f[v], f1[u] + f2[u]));
        par[v] = u;
    }
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        int maxChild = f1[u];
        if (f1[u] == f1[v] + 1)
        {
            if (f2[u] == f2[v] + 1) maxChild = f3[u];
            else maxChild = f2[u];
        }
 
        g[v] = max(f1[u] == f1[v] + 1 ? f2[u] : f1[u], g[u]) + 1;

        fPar[v] = max({fPar[u], g[u], maxChild, g[u] + maxChild});
        DFS(v, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFSPrepare(1, -1);
    DFS(1, -1);
    
    int res = n - 1;

    FOR(u, 1, n) for (auto &v : adj[u]) if (u == par[v])
    {
        int d1 = fPar[v];
        int d2 = f[v];

        mini(res, max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1}));
    }

    FOR(u, 1, n) cout << "debug: " << u << ' ' << f[u] << ' ' << fPar[u] << '\n';

    cout << res;

    return 0;
}