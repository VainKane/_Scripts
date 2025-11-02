#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define sz(v) ((int)v.size())
#define name "manage"

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e3 + 5;
int const oo = 1e9 + 1;

struct SegmentTree
{
    vector<int> t;
    int n;

    void Build(int v, int l, int r, vector<int> &a)
    {
        if (l == r) 
        {
            t[v] = a[l];
            return;
        }

        int mid = (l + r) >> 1;
        Build(2 * v, l, mid, a);
        Build(2 * v + 1, mid + 1, r, a);

        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

    SegmentTree(vector<int> vals = {0})
    {
        n = sz(vals) - 1;
        t.assign(4 * n, 0);
        if (n) Build(1, 1, n, vals);
    }

    void Update(int v, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            t[v] = val;
            return; 
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) Update(2 * v, l, mid, pos, val);
        else Update(2 * v + 1, mid + 1, r, pos, val);

        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

    int Get(int v, int l, int r, int left, int right)
    {
        if (l > left || r < right) return oo;
        if (left <= l && right >= r) return t[v];

        int mid = (l + r) >> 1;
        int m1 = Get(2 * v, l, mid, left, right);
        int m2 = Get(2 * v + 1, mid + 1, r, left, right);

        return min(m1, m2);
    }

    void Update(int pos, int val)
    {
        Update(1, 1, n, pos, val);
    }

    int Get(int l, int r)
    {
        if (l > r) return oo;
        return Get(1, 1, n, l, r);
    }
};

int n, m, q;
vector<int> adj[N];

int a[N];

bool visited[N];
int in[N], out[N];
int cnt = 0;

int pos[N];
bool inDeg[N];

SegmentTree it;

void DFS(int u)
{
    in[u] = ++cnt;
    for (auto &v : adj[u]) DFS(v, u);
    out[u] = cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        inDeg[u] = true;
    }

    FOR(u, 1, n) if (!inDeg[u]) 
    {
        // cout << "debug " << u << '\n';
        DFS(u);
    }

    vector<int> vals;
    vals.assign(n + 5, 0);
    
    FOR(u, 1, n) 
    {
        vals[in[u]] = a[u];
        // pos[i] = i;    
    }

    it = SegmentTree(vals);

    while (q--)
    {
        int type, u, v;
        cin >> type;

        if (type == 1)
        {
            cin >> u >> v;
            swap(pos[u], pos[v]);
        }
        else 
        {
            cin >> u;
            cout << it.Get(in[u], out[u]) << '\n';
        }
    }

    return 0;
}