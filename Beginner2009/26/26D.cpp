#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int v, w;
};

int const N = 1009;

int n;
int m;
int k;

vector<Edge> adj[N];
long long d[N][109];

void Dijkstra(int s)
{
    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= k; i++) d[s][i] = 0;

    vector<pair<int, int>> pq;
    pq.push_back({0, s});

    while (!pq.empty())
    {
        int u = (*pq.begin()).second;
        int du = (*pq.begin()).first;
        pq.erase(pq.begin());

        for (int i = 1; i <= k; i++)
        {
            if (du > d[u][i]) continue;

            for (auto e : adj[u])
            {
                int v = e.v;
                int w = e.w;

                int p = lower_bound(pq.begin(), pq.end(), make_pair(du + w, 0)) - pq.begin();
                if (pq[p].first == du + w) continue;

                d[v][p + 1] = du + w;
                
                int j = pq.size() - 1;
                while (j != p && j >= 0) 
                {
                    swap(pq[j], pq[j + 1]);
                    j--;
                }
                pq[p] = {du + w, v};
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Dijkstra(1);
    for (int i = 1; i <= k; i++)
    {
        cout << d[n][i] << ' ';
    }

    return 0;
}