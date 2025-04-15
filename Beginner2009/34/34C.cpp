#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()

int const N = 1e5 + 5;
int const LOG = 17;

int n;
int m;
int q;

vector<int> adj[N];

int in[N];
int out[N];
int low[N];
int par[N];

int up[N][LOG + 5];
int h[N];

int ccc = 0;
int ccId[N];

bool cut[N];
int cnt = 0;

vector<int> cc[N];

int Find(int u, int anc)
{
    for (int i = LOG; i >= 0; i--)
    {
        if (h[up[u][i]] <= h[anc]) continue;
        u = up[u][i];
    }

    return u;
}

void DFS(int u)
{
    low[u] = in[u] = ++cnt;
    ccId[u] = ccc;

    int child = (par[u] != 0);

    for (auto v : adj[u])
    {
        if (v == par[u]) continue;
        if (in[v]) low[u] = min(low[u], in[v]);
        else
        {
            par[v] = u;
            up[v][0] = u;
            h[v] = h[u] + 1;
            DFS(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= in[u])
            {
                cc[u].push_back(in[v]);
                child++;
            }
        }
    }

    if (child >= 2)
    {
        cut[u] = true;
        sort(all(cc[u]));
    }
    out[u] = cnt;
}

bool isChild(int v, int u)
{
    return (in[u] <= in[v] && in[v] <= out[u]);
}

bool Query1(int a, int b, int c, int d)
{
    if (in[c] > in[d]) swap(c, d);
    if (ccId[a] != ccId[b]) return false;
    
    if (low[d] != in[d]) return true;
    return (isChild(a, d) == isChild(b, d));
}

bool Query2(int a, int b, int c)
{
    if (ccId[a] != ccId[b]) return false;
    if (!cut[c]) return true;
    if (a == c || b == c) return false;

    int parA = 0;
    int parB = 0;
    if (isChild(a, c)) parA = Find(a, c);
    if (isChild(b, c)) parB = Find(b, c);

    if (parA == parB) return true;
    if (parA == 0 && low[parB] < in[c]) return true;
    if (parB == 0 && low[parA] < in[c]) return true;

    if (low[parA] < in[c] && low[parB] < in[c]) return true;

    return false;
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

    for (int i = 1; i <= n; i++) 
    {
        if (in[i]) continue;
        ccc++;
        DFS(i);
    }

    low[0] = 1e9;
    for (int u = 1; u <= n; u++)
    {
        for (int i = 1; i <= LOG; i++)
        {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
    }

    cin >> q;
    while (q--)
    {
        int type, a, b, c, d;
        cin >> type;

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
    }

    return 0;
}