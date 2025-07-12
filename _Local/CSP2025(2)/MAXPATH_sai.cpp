#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define name "MAXPATH"

struct Edge
{
    int v, w;
};

int const N = 1e5 + 5;

int n, m;
vector<Edge> adj[N];
Edge edges[N];
bool visited[N];
bool mark[N];

double res = 0;
int cnt = 0;

vector<int> b;
vector<int> nodes;

void Check(int d, int s)
{
    memset(visited, false, sizeof visited);
    nodes.clear();

    queue<int> q;
    q.push(s);

    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto e : adj[u]) if (e.w >= d && !visited[e.v])
        {
            visited[e.v] = true;
            q.push(e.v);
            nodes.push_back(e.v);            
        }
    }
}

int GCD(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

void Init()
{
    sort(all(b));
    b.erase(unique(all(b)), b.end());

    FOR(i, 1, m)
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        b.push_back(w);
        edges[i] = {u, w};
    }

    for (auto w : )
    
    cout << fixed << setprecision(2) << res / cnt;


    return 0;
}