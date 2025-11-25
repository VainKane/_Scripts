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

int const N = 309;
long long const oo = 1e18;

int n, m, c;
vector<int> adj[N];


int low[N], in[N];

int ccId[N];
int scc[N];

stack<int> st;
int timer = 0, cc = 0;
int bridges = 0;

int dp[N][N];

void Tarjan(int u, int p)
{
    low[u] = in[u] = ++timer;
    st.push(u);

    for (auto &v : adj[u]) if (v != p)
    {
        if (ccId[v]) continue;
        if (in[v]) mini(low[u], in[v]);
        else
        {
            Tarjan(v, u);
            mini(low[u], low[v]); 
            bridges += low[v] == in[v];
        }
    }

    if (low[u] == in[u])
    {
        int v = 0;
        cc++;

        while (v != u)
        {
            v = st.top(); st.pop();
            ccId[v] = cc;
        }
    }
}

void Reset()
{
    FOR(u, 1, n)
    {
        adj[u].clear();
        scc[u] = ccId[u] = in[u] = 0;
    }

    memset(dp, 0, sizeof dp);
    bridges = cc = timer = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m >> c;
        Reset();

        FOR(i, 1, m)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        FOR(u, 1, n) if (!in[u]) Tarjan(u, -1);
        FOR(u, 1, n) scc[ccId[u]]++;

        if (cc == 1)
        {
            cout << "-1\n";
            continue;
        }

        dp[0][0] = 1;
        FOR(i, 1, cc) REP(j, n)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= scc[i]) dp[i][j] |= dp[i - 1][j - scc[i]];
        }
        
        long long res = oo;
        FOR(i, 1, n - 1) if (dp[cc][i])
        {
            int cnt = n - i;
            mini(res, 1LL * i * i + 1LL * cnt * cnt);
        }

        // FOR(u, 1, n) cout << ccId[u] << ' ';
        // cout << '\n';
        // FOR(u, 1, cc) cout << scc[u] << ' ';
        // cout << "\n---\n";

        // res = 0;
        cout << res + 1LL * c * (cc - 1 - bridges) << '\n';
        // cout << bridges << '\n';
    }

    return 0;
}