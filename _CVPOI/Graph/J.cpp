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

int const N = 1e5 + 5;
int const oo = 1e9 + 4;

int n, c;
int s[N], p[N];
vector<int> adj[N];

int preS[N], preP[N];
map<int, int> mp[N];

int res = -oo;

void DFSPrepare(int u, int par)
{
    for (auto &v : adj[u]) if (v != par)
    {
        preS[v] = preS[u] + s[v];
        preP[v] = preP[u] + p[v];
        DFSPrepare(v, u);
    }
}

void DFS(int u, int par)
{
    mp[u][preS[u]] = preP[u];
    if (s[u] <= c) maxi(res, p[u]);

    for (auto &v : adj[u]) if (v != par)
    {
        DFS(v, u);
        if (sz(mp[u]) < sz(mp[v])) swap(mp[u], mp[v]);

        for (auto &pr : mp[v])
        {
            if (pr.F - preS[u] + s[u] <= c) maxi(res, pr.S - preP[u] + p[u]);

            auto &x = mp[u][pr.F];

            auto it = mp[u].find(pr.F);
            if (it == mp[u].end()) x = pr.S;
            else maxi(x, pr.S);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> c;
    FOR(i, 1, n) cin >> s[i];
    FOR(i, 1, n) cin >> p[i];

    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    preS[1] = s[1], preP[1] = p[1];
    DFSPrepare(1, -1);
    DFS(1, -1);

    cout << res;

    return 0;
}