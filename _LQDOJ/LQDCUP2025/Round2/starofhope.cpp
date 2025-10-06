#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define sz(v) ((int)v.size())
#define y1 __y1
#define name "starofhope"

template <class t> mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct Data
{
    long long du;
    int x, y;

    bool operator < (Data const other) const
    {
        return du > other.du;
    }
};

int const N = 1e5 + 5;

int m, n, p, q;

int x[N], y[N];
int ox[N], oy[N];
int x1[N], y1[N], x2[N], y2[N];

vector<pair<int, int>> adj[1009][1009];
int cnt = 0;

int d[1009][1009];



void Dijkstra()
{
    priority_queue<Data> pq;
    pq.push({0, 1, 1});
    d[1][1] = 0;
    
    while (!pq.empty())
    {
        int x = pq.top().x;
        int y = pq.top().y;
        long long du = pq.top().u;
        pq.pop();

        if (du > d[x][y]) continue;

        for (auto &p : adj[x][y])
        {
            int u = p.F;
            int v = p.S;

            if (mini(d[u][v], d[x][y] + ))
        }
    }
}

void Sub3()
{
    FOR(i, 0, p) FOR(j, 0, p) adj[i][j].clear();
    x[0] = 1; y[0] = 1;

    FOR(i, 0, p) FOR(j, i + 1, p)
    {
        if (x[i] == x[j] || y[i] == y[j])
        {
            if (x[i] == y[i]) continue;
            adj[x[i]][y[i]].push_back({x[j], y[j]});
            adj[x[j]][y[j]].push_back({x[i], y[i]});            
        }
    }
}

void Compress(int a[], int o[])
{
    vector<int> vals;
    
    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) 
    {
        o[i] = a[i];
        a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    int tests; cin >> tests;
    while (tests--)
    {
        cin >> m >> n >> p >> q;

        FOR(i, 1, p) cin >> x[i] >> y[i];
        FOR(i, 1, q) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

        Compress(x); Compress(y);
    }

    return 0;
}