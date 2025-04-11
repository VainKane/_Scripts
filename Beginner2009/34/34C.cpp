#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;
int const LOG = 17;

int n;
int m;
int q;

vector<int> adj[N];

int in[N];
int out[N];
int low[N];
int up[N][LOG + 5];
int h[N];

bool cut[N];

int cnt = 0;

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int d = h[u] - h[v];

    for (int i = 0; i <= LOG; i++)
    {
        if (bit(i, d))
        {
            u = up[u][i];
        }
    }

    if (u == v) return u;

    for (int i = LOG; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

void DFS(int u)
{
    low[u] = in[u] = ++cnt;
    int child = (up[u][0] != 0);

    for (auto v : adj[u])
    {
        if (v == up[u][0]) continue;
        if (in[v]) low[u] = min(low[u], in[v]);
        else
        {
            h[v] = h[u] + 1;
            up[v][0] = u;

            for (int i = 1; i <= LOG; i++)
            {
                up[v][i] = up[up[v][i - 1]][i - 1];
            }

            DFS(v);
            low[u] = min(low[u], low[v]);

            child += (low[v] >= in[u]);
        }
    }

    cut[u] = (child >= 2);
    out[u] = ++cnt;
}

bool isChild(int v, int u)
{
    return (in[u] <= in[v] && out[v] <= out[u]);
}

bool Query1(int a, int b, int c, int d)
{
    if (1ll * in[a] * in[b] == 0) return false;
    if (1ll * in[c] * in[d] == 0) return false;

    if (isChild(c, d))
    {
        if (up[c][0] == d && low[c] > in[d]) // cd la cau
        {
            bool c1 = isChild(a, c);
            bool c2 = isChild(b, c);
    
            return (c1 == c2);
        }
    }
    if (isChild(d, c))
    {
        if (up[d][0] == c && low[d] > in[c]) // cd la cau
        {
            bool c1 = isChild(a, d);
            bool c2 = isChild(b, d);
    
            return (c1 == c2);
        } 
    }
   
    return true;
}

bool Query2(int a, int b, int c)
{
    if (1ll * in[a] * in[b] * in[c] == 0) return false;
    if (!cut[c]) return true;
    
    bool c1 = (low[a] < in[c]);
    bool c2 = (low[b] < in[c]);

    if (up[c][0] != 0)
    {
        if (c1 != c2) return false; // 1 cha, 1 con
        if (c1 & c2) return true; // cung la cha
    }
    
    for (auto v : adj[c])
    {
        if (isChild(a, v)) a = v;
        if (isChild(b, v)) b = v;
    }

    return (a == b);
    // return (LCA(a, b) != c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) if (!in[i]) DFS(i);

    cin >> q;
    while (q--)
    {
        int type, a, b, c, d;
        cin >> type;

        // for (int i = 1; i <= n; i++) cout << i << ' ' << cut[i] << '\n';

        if (type == 1)
        {
            cin >> a >> b >> c >> d;

            if (Query1(a, b, c, d)) cout << "yes\n";
            else cout << "no\n";
        }
        else
        {
            cin >> a >> b >> c;

            if (Query2(a, b, c)) cout << "yes\n";
            else cout << "no\n";
        }

        // cout << "          par: " << up[2][0] << '\n';
        // cout << "          LCA: " << LCA(6, 2) << '\n';
    }

    return 0;
}