#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define F first
#define S second

struct Edge
{
    int v, w;
};

struct Query
{
    int i, l, h;
    long long r;
};

int const N = 1e5 + 5;

int n, m, q;
vector<Edge> adj[N];
int s[N];
int c[N];

long long d[N];

int nodes[N];
Query queries[N];
int res[N];

int t[4 * N];

vector<int> b;

bool cmp1(int a, int b) { return d[a] < d[b]; }
bool cmp2(Query a, Query b) { return a.r < b.r; }

void Dijkstra(int s)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});

    memset(d, 0x3f, sizeof d);
    d[s] = 0;

    while (!pq.empty())
    {
        int u = pq.top().S;
        long long du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto e : adj[u])
        {
            if (d[e.v] > d[u] + e.w)
            {
                d[e.v] = d[u] + e.w;
                pq.push({d[e.v], e.v});
            }
        }
    }
}

void Update(int v, int l, int r, int pos, int val)
{
    if (l == r)
    {
        t[v] = min(t[v], val);
        return;
    }

    int mid = l + (r - l) / 2;
    if (pos <= mid) Update(2 * v, l, mid, pos, val);
    else Update(2 * v + 1, mid + 1, r, pos, val);

    t[v] = min(t[2 * v], t[2 * v + 1]);
}

int GetMin(int v, int l, int r, int left, int right)
{
    if (l > right || r < left) return 1e9;
    if (left <= l && right >= r) return t[v];

    int mid = l + (r - l) / 2;
    int min1 = GetMin(2 * v, l, mid, left, right);
    int min2 = GetMin(2 * v + 1, mid + 1, r, left, right);
    
    return min(min1, min2);
}

void Input()
{
    cin >> n >> m >> q;
    
    for (int i = 1; i <= n; i++) cin >> s[i] >> c[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= q; i++)
    {
        int l, h;
        long long r;
        cin >> l >> h >> r;
        queries[i] = {i, l, h, r};
    }
}

int Get(int x)
{
    return lower_bound(all(b), x) - b.begin() + 1;
}

void Init()
{
    Dijkstra(1);

    for (int i = 1; i <= n; i++) b.push_back(s[i]);

    sort(all(b));
    b.erase(unique(all(b)), b.end());

    for (int i = 1; i <= n; i++) s[i] = Get(s[i]);
    for (int i = 1; i <= n; i++) nodes[i] = i;

    sort(nodes + 1, nodes + n + 1, cmp1);
    sort(queries + 1, queries + q + 1, cmp2);

    memset(t, 0x3f, sizeof t);
}

void Solve()
{
    int j = 0;

    for (int i = 1; i <= q; i++)
    { 
        while (d[nodes[j + 1]] <= queries[i].r && j < n) 
        {
            j++;
            int v = nodes[j];

            if (b[s[v] - 1] == 0) continue;
            Update(1, 1, b.size(), s[v], c[v]);
        }
        
        int pos = queries[i].i;
        int l = Get(queries[i].l);
        int h = upper_bound(all(b), queries[i].h) - b.begin();

        res[pos] = GetMin(1, 1, b.size(), l, h);
        if (res[pos] == 1e9) res[pos] = -1;
    }

    for (int i = 1; i <= q; i++) cout << res[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    Init();
    Solve();

    return 0;
}