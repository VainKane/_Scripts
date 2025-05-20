#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()

struct Edge
{
    int v, w;
};

struct VOI
{
    int u, v, w;
};

int const N = 1e5 + 5;

int n, k;
int v1, v2;

VOI a[N];
vector<Edge> adj[N];

double delta;
double res = 0;

bool visited[N];
int child[N];

vector<double> b;

void DFS(int u)
{
    visited[u] = true;
    child[u] = 1;

    for (auto e : adj[u])
    {
        int v = e.v;
        int w = e.w;

        if (visited[v]) continue;
        DFS(v);
        child[u] += child[v];
    }   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(2);

    cin >> n >> k >> v1 >> v2;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        a[i] = {u, v, w};
    }

    delta = ((double)1 / v1) - ((double)1 / v2);
    
    if (delta < 0) 
    {
        cout << 0.00;
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
        int u = a[i].u;
        int v = a[i].v;
        int w = a[i].w;
        
        memset(visited, 0, sizeof visited);
        DFS(u);
        
        cout << u << " - " << v << ": " <<  child[u] * (n - child[v]) << '\n';
    }

    return 0;
}