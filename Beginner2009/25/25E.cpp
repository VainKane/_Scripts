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

vector<int> res;

void BFSBuild(int start)
{
    queue<int> qu;
    qu.push(start);
    par[start] = -1;

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        for (auto v : adj[u])
        {
            if (par[v]) continue;
            par[v] = u;
            h[v] = h[u] + 1;

            qu.push(v);
        }
    }
}

bool CompareLCA(int u, int v)
{
    int uMin = 1e9;
    int vMin = 1e9;

    for (int i = LOG; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            uMin = min(uMin, upMin[u][i]);
            vMin = min(vMin, upMin[v][i]);

            u = up[u][i];
            v = up[v][i];
        }
    }

    uMin = min(uMin, u);
    vMin = min(vMin, v);

    return uMin < vMin;
}

void BFS(int root)
{
    queue<int> qu;
    qu.push(root);

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        for (auto v : adj[u])
        {
            if (h[v] != h[u] + 1) continue;
            if (CompareLCA(u, par[v])) par[v] = u;

            qu.push(v);
        }

        up[u][0] = u;
        upMin[u][0] = min(u, u);

        for (int i = 1; i <= LOG; i++)
        {
            int p = up[u][i - 1];
            up[u][i] = up[p][i - 1];
            upMin[u][i] = min(upMin[u][i - 1], upMin[p][i - 1]);
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

    BFSBuild(s);
    BFS(s);

    res.push_back(t);

    while (s != t)
    {
        t = par[t];
        res.push_back(t);
    }

    reverse(res.begin(), res.end());
    for (auto val : res) cout << val << ' ';

    return 0;
}