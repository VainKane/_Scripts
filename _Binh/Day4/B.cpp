#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1009;

int m, n;
char a[N][N];

int h[N * N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int cnt = 0;
int ccId[N][N];

vector<int> adj[N];
int res = 0;

bool Inside(int x, int y)
{
    return  x >= 1 && x <= m &&
            y >= 1 && y <= n;
}

void DFS(int x, int y, int id)
{
    ccId[x][y] = id;
    
    REP(i, 4)
    {
        int u = x + dx[i];
        int v = y + dy[i];

        if (!Inside(u, v) || ccId[u][v] || a[u][v] != a[x][y]) continue;
        DFS(u, v, id);
    }
}

void DFS(int u, int p)
{
    maxi(res, h[u]);

    for (auto &v : adj[u]) if (!h[v])
    {
        h[v] = h[u] + 1;
        DFS(v, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    FOR(i, 1, m) FOR(j, 1, n) if (!ccId[i][j] && a[i][j] != '*') DFS(i, j, ++cnt);

    h[1] = 1;

    FOR(x, 1, m) FOR(y, 1, n) REP(i, 4)
    {
        int u = x + dx[i];
        int v = y + dy[i];

        int id1 = ccId[x][y];
        int id2 = ccId[u][v];

        if (!Inside(u, v) || id1 == id2 || a[u][v] == '*') continue;
        adj[id1].push_back(id2);
    }

    FOR(u, 1, cnt)
    {
        sort(all(adj[u]));
        adj[u].erase(unique(all(adj[u])), adj[u].end());
    }

    h[1] = 1;
    DFS(1, -1);

    cout << res;

    return 0;
}