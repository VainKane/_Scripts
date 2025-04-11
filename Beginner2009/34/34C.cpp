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

int ccc = 0;
int ccId[N];

bool cut[N];
int cnt = 0;

vector<int> cc[N];

void DFS(int u)
{
    low[u] = in[u] = ++cnt;
    int child = (par[u] != 0);
    ccId[u] = ccc;

    for (auto v : adj[u])
    {
        if (v == par[u]) continue;
        if (in[v]) low[u] = min(low[u], in[v]);
        else
        {
            par[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
            child += (low[v] >= in[u]);
        }
    }

    if (child >= 2)
    {
        cut[u] = true;
        for (auto v : adj[u]) 
        {
            cc[u].push_back(v);
        }

        sort(all(cc[u]));
    }
    out[u] = ++cnt;
}

bool isChild(int v, int u)
{
    return (in[u] <= in[v] && out[v] <= out[u]);
}

bool Query1(int a, int b, int c, int d)
{
    if (isChild(c, d)) swap(c, d);
    if (ccId[a] != ccId[b]) return false;
    
    if (low[d] == in[d])
    {
        return (isChild(a, d) == isChild(b, d));
    }

    return true;
}

bool Query2(int a, int b, int c)
{
    if (ccId[a] != ccId[b]) return false;
    if (!cut[c]) return true;
    if (a == c || b == c) return false;
    
    bool ca = isChild(a, c);
    bool cb = isChild(b, c);

    if (!ca && !cb) return true;
    if (!ca || !cb) return false;

    auto it1 = upper_bound(all(cc[c]), in[a]);
    auto it2 = upper_bound(all(cc[c]), in[b]);

    return it1 == it2;
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
        // cout << "             " << ccc;
        // cout << cnt;
    }

    return 0;
}