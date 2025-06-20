#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define name "query"

struct Node
{
    int x[16];

    Node()
    {
        for (int i = 0; i <= 15; ++i) x[i] = -1e9; // x[0] unused
    }

    static Node Empty()
    {
        return Node();
    }
};

const int N = 305;
int t, n, q;
vector<int> adj[N];
int cnt, in[N], out[N];
bool odd[N];
vector<int> a1, a0;
Node t1[4 * N], t0[4 * N];
int lz1[4 * N], lz0[4 * N];

void Merge(Node &v, const Node &a, const Node &b)
{
    int l = 1, r = 1;
    for (int i = 1; i <= 15; i++)
    {
        if (a.x[l] > b.x[r])
            v.x[i] = a.x[l++];
        else
            v.x[i] = b.x[r++];
    }
}

void Build(Node t[], int v, int l, int r)
{
    if (l == r)
    {
        t[v].x[1] = 0;
        return;
    }

    int mid = (l + r) / 2;
    Build(t, 2 * v, l, mid);
    Build(t, 2 * v + 1, mid + 1, r);
    Merge(t[v], t[2 * v], t[2 * v + 1]);
}

void Push(Node t[], int lz[], int v)
{
    if (lz[v])
    {
        for (int i = 1; i <= 15; i++)
        {
            t[2 * v].x[i] += lz[v];
            t[2 * v + 1].x[i] += lz[v];
        }
        lz[2 * v] += lz[v];
        lz[2 * v + 1] += lz[v];
        lz[v] = 0;
    }
}

void Update(Node t[], int lz[], int v, int l, int r, int left, int right, int val)
{
    if (l > right || r < left)
        return;
    if (left <= l && r <= right)
    {
        for (int i = 1; i <= 15; i++)
            t[v].x[i] += val;
        lz[v] += val;
        return;
    }

    Push(t, lz, v);
    int mid = (l + r) / 2;
    Update(t, lz, 2 * v, l, mid, left, right, val);
    Update(t, lz, 2 * v + 1, mid + 1, r, left, right, val);
    Merge(t[v], t[2 * v], t[2 * v + 1]);
}

Node Get(Node t[], int lz[], int v, int l, int r, int left, int right)
{
    if (l > right || r < left)
        return Node::Empty();
    if (left <= l && r <= right)
        return t[v];

    Push(t, lz, v);
    int mid = (l + r) / 2;
    Node a = Get(t, lz, 2 * v, l, mid, left, right);
    Node b = Get(t, lz, 2 * v + 1, mid + 1, r, left, right);
    Node res;
    Merge(res, a, b);
    return res;
}

void DFS(int u)
{
    in[u] = ++cnt;
    if (odd[u])
        a1.push_back(in[u]);
    else
        a0.push_back(in[u]);
    for (int v : adj[u])
    {
        odd[v] = !odd[u];
        DFS(v);
    }
    out[u] = cnt;
}

void Init()
{
    a1 = {0};
    a0 = {0};
    odd[1] = 1;
    cnt = 0;
    DFS(1);
    Build(t1, 1, 1, a1.size() - 1);
    Build(t0, 1, 1, a0.size() - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name ".inp", "r", stdin);
    // freopen(name ".out", "w", stdout);

    cin >> t >> n;
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    Init();
    cin >> q;

    while (q--)
    {
        string type;
        cin >> type;

        if (type == "get")
        {
            int u;
            cin >> u;
            if (odd[u])
            {
                int idx = lower_bound(all(a1), in[u]) - a1.begin() + 1;
                cout << Get(t1, lz1, 1, 1, a1.size() - 1, idx, idx).x[1] << ' ';
            }
            else
            {
                int idx = lower_bound(all(a0), in[u]) - a0.begin() + 1;
                cout << Get(t0, lz0, 1, 1, a0.size() - 1, idx, idx).x[1] << ' ';
            }
            continue;
        }

        int u, k;
        cin >> u >> k;

        int l1 = lower_bound(all(a1), in[u]) - a1.begin() + 1;
        int r1 = upper_bound(all(a1), out[u]) - a1.begin();
        int l0 = lower_bound(all(a0), inin[u]) - a0.begin() + 1;
        int r0 = upper_bound(all(a0), out[u]) - a0.begin();

        if (type == "add")
        {
            int d = odd[u] ? 1 : -1;
            if (l1 <= r1)
                Update(t1, lz1, 1, 1, a1.size() - 1, l1, r1, k * d);
            if (l0 <= r0)
                Update(t0, lz0, 1, 1, a0.size() - 1, l0, r0, k * -d);
        }
        else if (type == "pos")
        {
            Node m1 = Get(t1, lz1, 1, 1, a1.size() - 1, l1, r1);
            Node m2 = Get(t0, lz0, 1, 1, a0.size() - 1, l0, r0);
            Node res;
            Merge(res, m1, m2);
            cout << res.x[k] << ' ';
        }
    }

    return 0;
}
