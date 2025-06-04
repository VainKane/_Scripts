#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

struct Edge
{
    int v, w;
};

int const N = 1e5 + 5;

int n, m, q;
vector<Edge> adj[N];

int s[N];
int c[N];

long long d[N];

void Dijkstra(int s)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});

    memset(d, 0x3f, sizeof d);
    d[s] = 0;

    while (!pq.empty())
    {
        int u = pq.top().S;
        long long du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto e : adj[u])
        {
            if (d[e.v] > d[u] + e.w)
            {
                d[e.v] = d[u] + e.w;
                pq.push({d[e.v], e.v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    
    for (int i = 1; i <= n; i++) cin >> s[i] >> c[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Dijkstra(1);

    while (q--)
    {
        int l, h;
        long long r;
        cin >> l >> h >> r;

        int res = 1e9;

        for (int u = 1; u <= n; u++)
        {
            if (d[u] > r) continue;
            if (s[u] >= l && s[u] <= h) res = min(res, c[u]);
        }

        if (res == 1e9) res = -1;
        
        cout << res << '\n';
        if (q <= 5) cerr << res << '\n';
    }

    return 0;
}