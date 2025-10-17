#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 2e5 + 5;

int n;
vector<int> adj[N];

int a[N];
int h[N], f[N];

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        f[u] += f[v] + 1;
        h[v] = h[u] + 1;
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
    FOR(i, 1, n) cin >> a[i];

    DFS(1, -1);

    long long res = 0;
    FOR(u, 1, n)
    {
        res += f[u];
        // if (a[u] != a[1]) res -= h[u];
    } 
        
    cout << res;

    return 0;
}