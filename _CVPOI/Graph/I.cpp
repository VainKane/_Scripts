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
    int u, v, w;
};

int const N = 5e5 + 5;
int const MOD = 1e9 + 7;

int n, m;

Edge edges[N];
vector<int> adj[N];
vector<int> dagADj[N];

int inDeg[N];
vector<int> topo;

int dp[N];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

bool cmp(int i, int j)
{
    return edges[i].w < edges[j].w;
}

void BFS()
{
    queue<int> q;
    FOR(u, 1, n) if (!inDeg[u]) q.push(u);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        topo.push_back(u);
        for (auto &v : dagADj[u]) if (!--inDeg[v]) q.push(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
        adj[u].push_back(i);
        adj[v].push_back(i);
    }

    FOR(u, 1, n)
    {
        sort(all(adj[u]), cmp);
        vector<int> nodes[2];

        int cur = 0;

        for (auto &id : adj[u])
        {
            if (nodes[cur].empty() || edges[id].w == edges[nodes[cur]].w) nodes[cur].push_back(id);
            else
            {
                cur ^= 1;
            }
        }
    }

    BFS();
    FOR(u, 1, m) dp[u] = 1;

    int res = 0;
    for (auto &u : topo) 
    {
        Add(res, dp[u]);
        for (auto &v : dagADj[u]) Add(dp[v], dp[u]);
    }
    
    // cout << res;

    FOR(u, 1, m)
    {
        cout << "Adj of " << u << ":\n";
        for (auto &v : adj[u]) cout << v << ' ';
        cout << '\n';
    }

    return 0;
}