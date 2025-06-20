#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int v, w;
};

int const N = 3e5 + 5;

int n, q;
vector<Edge> adj[N];

vector<int> child[N];
bool leaf[N];
long long d[N];

int par[N];
int sz[N];

long long res = 1e18;

void DFS(int u)
{
    for (auto e : adj[u])
    {
        d[e.v] = d[u] + e.w;
        DFS(e.v); 
        if (leaf[e.v]) child[u].push_back(e.v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(leaf, 1, sizeof leaf);

    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int p, c; 
        cin >> p >> c;
        
        adj[p].push_back({i, c});
        leaf[p] = false;
    }

    DFS(1);

    for (int i = 1; i <= q; i++)
    {
        
    }

    return 0;
}