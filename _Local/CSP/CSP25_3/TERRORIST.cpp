#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define BIT(i, x) (((x) >> (i)) & 1)
#define name "TERRORIST"

int const N = 2e5 + 5;
int const LOG = 18;

int n, m;
vector<int> adj[N];

int h[N];
int up[N][22];

void DFS(int u, int p)
{
    for (auto v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        up[v][0] = u;
        DFS(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);

    int delta = h[u] - h[v];
    FOR(i, 0, LOG) if (BIT(i, delta)) u = up[u][i];

    if (u == v) return u;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

void Sub2()
{
    DFS(1, -1);

    FOR(j, 1, LOG) FOR(i, 1, n)
        up[i][j] = up[up[i][j - 1]][j - 1];

    int q; cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        int p = LCA(x, y);
        int res = h[x] + h[y] - 2 * h[p];

        cout << res << ' ' << res << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (m == n - 1) Sub2();

    return 0;
}

