#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(l, val);
        Update(r + 1, -val);
    }

    int Get(int idx)
    {
        int res = 0;

        while (idx)
        {
            res += bit[idx];
            idx ^= idx & -idx;
        }

        return res;
    }
};

struct SegmentTree
{
    vector<int> t;
    vector<int> lz;
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
    
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    SegmentTree(vector<int> a = {0})
    {
        n = sz(a) - 1;
        t.assign(4 * n, 0);
        lz.assign(4 * n, 0);
        if (n) Build(1, 1, n, a);
    }

    void Push(int v)
    {
        if (lz[v])
        {
            FOR(u, 2 * v, 2 * v + 1)
            {
                t[u] = lz[v];
                lz[u] = lz[v];
            }

            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v] = val;
            lz[v] = val;
            return;
        }

        Push(v);

        int mid = (l + r) >> 1;
        Update(2 * v, l, mid, left, right, val);
        Update(2 * v + 1, mid + 1, r, left, right, val);

        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    int Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return 0;
        if (left <= l && right >= r) return t[v];

        Push(v);

        int mid = (l + r) >> 1;
        int m1 = Get(2 * v, l, mid, left, right);
        int m2 = Get(2 * v + 1, mid + 1, r, left, right);

        return max(m1, m2);
    }

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }

    int Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(1, 1, n, l, r);
    }
};  

int const N = 2e5 + 5;

int n;

int a[N], b[N];
SegmentTree it;

vector<int> vals;

int GetId(int const &x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Compress()
{
    FOR(i, 1, n) 
    {
        vals.push_back(a[i]);
        vals.push_back(b[i]);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) 
    {
        a[i] = GetId(a[i]);
        b[i] = GetId(b[i]);
    }
}

int GetPos(int x)
{
    int l = 0;
    int r = n;
    int res = l;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (it.Get(1, mid) <= x)
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    it = SegmentTree(n);
    FOR(i, 1, n) it.Update(i, i, a[i]);

    FOR(i, 1, n)
    {
        int j = GetPos(b[i]);
        if (!j) continue;

        
    }

    return 0;
}