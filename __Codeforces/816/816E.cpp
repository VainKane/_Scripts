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

int const N = 5009;

int n, s;

int a[N], b[N];
vector<int> adj[N];

long long d[N];

long long dp[N][N][2];
long long f[2][N][2];
int sz[N];

void DFSPrepare(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        d[v] = d[u] + a[v] - b[v];
        DFSPrepare(v, u);
    }
}

void DFS(int u, int p)
{
    dp[u][0][0] = 0;

    bool cur = 1;
    memset(f[cur], 0x3f, sizeof f[cur]);
    f[cur][0][0] = 0;

    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        cur ^= 1;
        memset(f[cur], 0x3f, sizeof f[cur]);

        FOR(k1, 0, sz[u]) REP(r1, 2) FOR(k2, 0, sz[v]) REP(r2, 2)
        {
            bool nR = (r1 & k1) | (r2 & k2);
            mini(f[cur][k1 + k2][nR], f[cur ^ 1][k1][r1] + dp[v][k2][r2]);
        }
 
        sz[u] += sz[v];
    }

    // if (u == 1) cout << "debug: " << f[cur][3][0] << '\n';

    sz[u]++;
    FOR(k, 0, sz[u])
    {
        dp[u][k][0] = min(f[cur][k - 1][0] + a[u], f[cur][k][0]);

        mini(dp[u][k][1], f[cur][k - 1][0] + d[u]);
        mini(dp[u][k][1], f[cur][k - 1][1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;
    cin >> a[1] >> b[1];
    FOR(i, 2, n)
    {
        int p;
        cin >> a[i] >> b[i] >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    memset(dp, 0x3f, sizeof dp);

    d[1] = a[1] - b[1];
    DFSPrepare(1, -1);
    DFS(1, -1);

    // FORD(k, n, 1) REP(r, 2) if (dp[1][k][r] <= s)
    // {
    //     cout << k;
    //     return 0;
    // }

    // cout << dp[2][4][0];
    cout << dp[1][3][0];
    // cout << dp[9][2][0];

    // FOR(u, 1, n)
    // {
    //     cout << "Adj of " << u << ":\n";
    //     for (auto &v : adj[u]) cout << v << ' ';
    //     cout << '\n';
    // }

    return 0;
}