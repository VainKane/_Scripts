#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;
int const LOG = 17;

int n;
int m;
int s;
int t;

vector<int> adj[N];

int h[N];
int par[N];

int up[N][LOG + 5];
int upMin[N][LOG + 5];

bool visisted[N];

vector<int> res;

void Build(int start)
{
    queue<int> qu;
    qu.push(start);
    visisted[start] = true;

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        for (auto v : adj[u])
        {
            if (visisted[v]) continue;
            
            visisted[v] = true;
            h[v] = h[u] + 1;
            
            if (v == t) return;
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
    if (h[root] == 0)
    {
        cout << -1;
        exit(0);
    }

    queue<int> qu;
    qu.push(root);

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        if (u == s) return;

        for (auto v : adj[u])
        {
            if (h[v] == h[u] - 1)
            {
                if (par[u] == 0 || CompareLCA(v, par[u])) par[u] = v;
            }
        }
        
        up[u][0] = par[u];
        upMin[u][0] = min(u, par[u]);

        for (int i = 1; i <= LOG; i++)
        {
            int p = up[u][i - 1];
            up[u][i] = up[p][i - 1];
            upMin[u][i] = min(upMin[u][i - 1], upMin[p][i - 1]);
        }

        qu.push(par[u]);
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

    Build(s);
    BFS(t);

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