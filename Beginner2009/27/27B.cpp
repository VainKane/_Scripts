#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int v, w;
};

int const N = 109;

int n; 
int m;

vector<Edge> adj[N];
vector<Edge> adjTmp[N];
int a, b, c;

int d1[N];
int d2[N];
int d3[N];

void Dijkstra(int s, int d[])
{
    d[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();

        if (du != d[u]) continue;

        for (auto &e : adj[u])
        {
            int v = e.v;
            int w = e.w;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        adjTmp[u] = adj[u];
        adjTmp[v] = adj[v];
    }

    cin >> a >> b >> c;

    memset(d1, 0x3f, sizeof d1);
    memset(d2, 0x3f, sizeof d2);
    memset(d3, 0x3f, sizeof d3);

    Dijkstra(a, d1, trace1);
    Dijkstra(b, d2, trace2);
    Dijkstra(c, d3, trace3);

    int res = 1e9;

    for (int v = 1; v <= n; v++)
    {
        res = min(res, d1[v] + d2[v] + d3[v]);
        if (v == 4) cout << d1[v] << ' ' << d2[v] << ' ' << d3[v] << '\n';
    }

    cout << res;

    return 0;
}