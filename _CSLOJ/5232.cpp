#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

struct SegmentTree
{
    vector<long long> t;
    vector<int> lz;
    vector<int> len;
    int n;

    void Build(int v, int l, int r)
    {
        len[v] = r - l + 1;

        if (l == r) return;
        int mid = (l + r) >> 1;

        Build(2 * v, l, mid);
        Build(2 * v + 1, mid + 1, r);
    }

    SegmentTree (int _n = 0)
    {
        n = _n; 
        t.assign(4 * n, 0);
        lz.assign(4 * n, 0);
        len.assign(4 * n, 0);
        if (n) Build(1, 1, n);
    }

    void Push(int v)
    {
        if (lz[v])
        {
            FOR(u, 2 * v, 2 * v + 1)
            {
                t[u] += lz[v] * len[u];
                lz[u] += lz[v] * len[u];
            }
            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r) 
        {
            t[v] += val * len[v];
            lz[v] += val * len[v];
            return;
        }

        Push(v);

        int mid = (l + r) >> 1;
        Update(2 * v, l, mid, left, right, val);
        Update(2 * v + 1, mid + 1, r, left, right, val);

        t[v] = t[2 * v] + t[2 * v + 1];
    }

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }
};

struct Event
{
    int type, x, y1, y2;

    bool operator < (Event const other) const
    {
        return x < other.x;
    }
};

int const N = 1e5 + 5;

int n;
SegmentTree it(N);
Event events[2 * N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        y1++; y2++;

        events[i] = {1, x1, y1, y2};
        events[n + i] = {-1, x2, y1, y2};
    }

    sort(events + 1, events + 2 * n + 1);

    long long res = 0;

    FOR(i, 1, 2 * n)
    {
        int type = events[i].type;
        int x = events[i].x;
        int y1 = events[i].y1;
        int y2 = events[i].y2;

        res += it.t[1] * (events[i].x - events[i - 1].x);
        it.Update(y1, y2 - 1, type);
    }

    cout << res;

    // FOR(i, 1, 2 * n + 1) cout << i << ' ' << events[i].type << ' ' << events[i].x << '\n';

    return 0;
}