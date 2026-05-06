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

int const N = 3009;
int const M = 3509;
int const MOD = 31333;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n, m;

int a[N];
vector<int> adj[N];

int dp[N][M];
int f[2][M];
int s[N];

int pw[N];
int sz[N];

void DFSPrepare(int u, int p)
{
    sz[u] = 1;
    for (auto &v : adj[u]) if (v != p)
    {
        DFSPrepare(v, u);
        sz[u] += sz[v];
    }
}

void DFS(int u, int p)
{
    dp[u][0] = pw[sz[u] - 1];
    bool cur = 1;

    memset(f[cur], 0, (m + 1) * sizeof (int));
    f[cur][0] = 1;

    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        cur ^= 1;
        memset(f[cur], 0, (m + 1) * sizeof (int));

        FOR(s1, 0, min(m, s[u])) FOR(s2, 0, min(s[v], m - s1))
            Add(f[cur][s1 + s2], f[cur ^ 1][s1] * dp[v][s2] % MOD);

        s[u] += s[v];
    }

    s[u] += a[u];
    FOR(j, a[u], min(m, s[u])) dp[u][j] = f[cur][j - a[u]];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    FOR(i, 1, n) cin >> a[i];

    pw[0] = 1;
    FOR(i, 1, n) pw[i] = 2 * pw[i - 1] % MOD;

    DFSPrepare(1, -1);
    DFS(1, -1);
    cout << dp[1][m];

    return 0;
}