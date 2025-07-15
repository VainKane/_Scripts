#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "traffic"

struct Edge
{
    int u, v;

    int GetOther(int p)
    {
        return v ^ u ^ p;
    }

    int GetCost(int p)
    {
        return v != p;
    }
};

int const N = 3005;

int t;
int n;
vector<int> adj[N];
Edge edges[N];

int rootCost;
int cost[N];

void DFS(int u, int par)
{
    for (auto i : adj[u])
    {
        int v = edges[i].GetOther(u);
        if (v == par) continue;

        rootCost += edges[i].GetCost(u);
        cost[v] = cost[u] + edges[i].GetCost(v) - edges[i].GetCost(u);
        DFS(v, u);
    }
}

void Solve()
{
    int res = 1e9;

    FOR(root, 1, n) 
    {
        memset(cost, 0, sizeof cost);
        rootCost = 0;

        DFS(root, -1);

        int a, b;
        a = b = 0;

        FOR(u, 1, n) if (u != root)
        {
            if (cost[u] < cost[a]) b = a, a = u;
            else if (cost[u] < cost[b]) b = u;
        }

        res = min(res, rootCost);
        if (adj[root].size() > 1)
        {
            int tmp = rootCost + cost[a] + cost[b];
            if (tmp < res)
            {
                res = tmp;
                cout << rootCost << ' ' << cost[a] << ' ' << cost[b] << ' ' << root << '\n';
            }
        }

        // if (root == 5) cout << "cost 5: " << rootCost;
    }

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cost[0] = 1e9;

    cin >> t;
    while (t--)
    {
        cin >> n;

        FOR(i, 1, n) adj[i].clear();
        FOR(i, 1, n - 1)
        {
            int u, v;
            cin >> u >> v;
            
            edges[i] = {u, v};
            adj[u].push_back(i);
            adj[v].push_back(i);
        }
        
        Solve();
    }

    return 0;
}