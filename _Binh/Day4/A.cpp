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

struct SegmentTree
{
    vector<int> t;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assgin(4 * n, 0);
    }

    void Update(int v, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            t[v] = val;
            return;
        }

        int mid = (l + r) >> 1;
        Update(2 * v, l, mid, pos, val);
        Update(2 * v + 1, mid + 1, r, pos, val);

        t[v] = t[2 * v] + t[2 * v + 1];
    }

    int Get(int v, int l, int r, int left, int right, int k)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r) return t[v];

        int mid = (l + r) >> 1;
        int val1 = Get(2 * v, l, mid, left, right, k);
        
        if (k <= val1) 
    }
};

int const N = 1e5 + 5;

int n;
long long m;

bool used[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> n >> m)
    {
        if (n == -1) return 0;
    
        set<int> s;
        FOR(i, 1, n) s.insert(i);

        FOR(i, 1, n)
        {
            long long cnt = 1LL * (n - i) * (n - i - 1);


        }
    }

    return 0;
}