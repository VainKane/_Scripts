#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define name "raspored"

int const N = 3e5 + 5;

int subtask;
int n, q;

int t[N], d[N];

long long s = 0;

struct Node
{
    vector<int> x;

    long long sum = 0;
    int sz = 1;

    void Merge(Node &a, Node &b)
    {
        int l = 0, r = 0;
        long long tmp = 0;

        REP(i, sz)
        {
            if (a.x[l] < b.x[r] && l < a.sz) x[i] = a.x[l++];
            else if (b.x[r] < a.x[l] && r < b.sz) x[i] = b.x[r++];

            tmp += x[i];
            sum += tmp;
        }
    }
};

struct SegmentTree
{
    vector<Node> t;
    Node haha;

    void Build(int v, int l, int r)
    {
        if (l == r)
        {
            t[v].x.push_back(d[l]);
            return;
        }

        int mid = (l + r) / 2;
        Build(2 * v, l, mid);
        Build(2 * v + 1, mid + 1, r);

        t[v].x.resize(t[2 * v].sz + t[2 * v + 1].sz);
        t[v].Merge(t[2 * v], t[2 * v + 1]);
    }

    SegmentTree(int n)
    {
        haha.x.push_back(1);
        t.resize(4 * n + 5);
        Build(1, 1, n);
    }

    void Update(int v, int l, int r, int pos, int val)
    {
        if (l == r)
        {   
            haha.x[0] = val;
            t[v].Merge(t[v], haha);
            return;
        }

        int mid = (l + r) / 2;
        if (pos <= mid) Update(2 * v, l, mid, pos, val);
        else Update(2 * v + 1, mid + 1, r, pos, val);

        t[v].Merge(t[2 * v], t[2 * v + 1]);
    }

    void Update(int pos, int val)
    {
        Update(1, 1, n, pos, val);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> subtask;
    cin >> n >> q;
    FOR(i, 1, n) cin >> t[i] >> d[i], s += t[i];

    // SegmentTree it(n);
    // cout << it.t[1].sum;

    while (q--)
    {
        int idx, ti, di;
        cin >> idx >> ti >> di;

        s -= t[idx];
        t[idx] = ti;
        s += t[idx];

        
    }

    return 0;
}