#include <bits/stdc++.h>

using namespace std;

#define name "graph"

int const N = 1e5 + 5;
int const LOG = 17;
int const maxLOG = 20;

int n, m, k;
vector<int> adj[N];
int up[N][maxLOG];
int h[N];

bool visited[N];

int a[N];
int b[N];

int res = 1e9;

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

void BFS(int s)
{
    queue<int> qu;
    qu.push(s);

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        visited[u] = true;

        for (auto v : adj[u])
        {
            if (visited[v]) continue;
            h[v] = h[u] + 1;
            up[v][0] = u;
            qu.push(v);
        }
    }
}

void Init()
{
    BFS(1);
    for (int i = 1; i <= LOG; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
    }
}

int LCA(int u, int v)
{
    if (h[v] > h[u]) swap(u, v);
    int d = h[u] - h[v];

    for (int i = 0; i <= LOG; i++)
    {
        if (bit(i, d)) u = up[u][i];
    }

    if (u == v) return u;

    for (int i = LOG; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];

    for (int i = 1; i <= n; i++)
    {
        int d; cin >> d;
        while (d--)
        {
            int u; cin >> u;
            adj[i].push_back(u);
        }
    }

    Init();

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int u = a[i];
            int v = b[j];

            if (!visited[u]) continue;
            if (!visited[v]) continue;

            int p = LCA(u, v);
            res = min(res, h[u] - h[p] + h[v]);
        }
    }

    if (res == 1e9)
    {
        cout << "impossible";
        exit(0);
    }

    cout << res;

    return 0;   
}