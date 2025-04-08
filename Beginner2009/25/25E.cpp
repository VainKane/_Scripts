#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;
int const LOG = 17;

int n;
int m;
int s;
int t;

vector<int> adj[N];

int par[N];
int h[N];
int trace[N];

int up[N][LOG];
int upMin[N][LOG];

void DFS(int u)
{
    for (auto v : adj[u])
    {
        if (v == par[u]) continue;

        par[v] = u;
        h[v] = h[u] + 1;
        DFS(v);
    }
}

int LCA(int u, int v)
{
    
}

void BFS(int root)
{
    memset(par, 0, sizeof par);

    queue<int> qu;
    qu.push(root);

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        for (auto v : adj[u])
        {
            if (h[v] != h[u] + 1) continue;
            if (!par[v]) continue;
            Update(u, par[v]);

            for (int i = 1; i <= LOG; i++)
            {
                up[v][] 
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}