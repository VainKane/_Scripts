#include <bits/stdc++.h> 

using namespace std;

int const N = 1e4 + 5;

int n;
int m;
vector<int> adj[N];

int par[N];
int id[N];
int low[N];

int cnt = 0;

int bridges = 0;
int cut = 0;

void DFS(int u)
{
    low[u] = id[u] = ++cnt;
    int nodes = (par[u] != 0);
    
    for (auto v : adj[u])
    {
        if (v == par[u]) continue;
        if (id[v]) low[u] = min(low[u], id[v]);
        else
        {
            par[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);

            if (low[v] == id[v]) bridges += 1;
            if (low[v] >= id[u]) nodes++;
        }
    }
    if (nodes >= 2) cut++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!id[i]) DFS(i);
    }

    cout << cut << ' ' << bridges;

    return 0;
}