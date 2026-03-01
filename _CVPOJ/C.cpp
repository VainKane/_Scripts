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

struct Edge
{
    int u, v, p;

    int GetOther(int node)
    {
        return node ^ u ^ v;
    }

    void Input()
    {
        cin >> u >> v >> p;
        p &= 1;
    }
};

int const N = 2e5 + 5;
long long const oo = 1e18;

int n;

Edge edges[N];
vector<int> adj[N];

long long f[N][2];

long long cur = 0;

void DFS(int u, int p)
{
    long long tmp = 1;

    for (auto &id : adj[u])
    {
        int v = edges[id].GetOther(u);
        int pt = edges[id].p;
        
        if (v == p) continue;
        DFS(v, u);
        REP(i, 2) f[u][i] += f[v][i ^ pt] + 1;
        tmp *= (f[v][pt] + (pt == 0));
    }

    cur += tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n - 1)
    {
        edges[i].Input();
        adj[edges[i].u].push_back(i);
        adj[edges[i].v].push_back(i);
    }

    DFS(1, -1);
    long long res = abs(cur - n * (n + 1) / 2);

    FOR(i, 1, n - 1)
    {
        edges[i].p ^= 1;
        
        cur = 0;
        DFS(1, -1);
        mini(res, abs(cur - n * (n + 1) / 2));
        
        edges[i].p ^= 1;
    }

    cout << res;

    return 0;
}