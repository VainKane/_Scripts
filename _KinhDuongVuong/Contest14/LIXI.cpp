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

struct FenwickTree
{
    vector<long long> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, long long val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    long long Get(int idx)
    {
        long long res = 0;

        while (idx)
        {
            res += bit[idx];
            idx ^= idx & -idx;
        }

        return res;
    }

    long long Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(r) - Get(l - 1);
    }
};

int const N = 1e5 + 5;

int n, k;
int a[N];

FenwickTree bit1, bit2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    FOR(i, 1, n) cin >> a[i];

    int q; cin >> q;
    while (q--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            pair<int, long long> b[k + 2];
            FOR(i, 1, k)
            {
                cin >> b[i].F;
                b[i].S = bit1.Get(b[i].F, b[i].F);
            }

            b[k + 1] = b[1];
        
            FOR(i, 1, k)
            {
                int id = b[i].F;
                bit2.Update(id, b[i + 1].S - b[i].S);
                bit2.Update(id, b[i + 1].S - bit1.Get(id, id));
            }
        }
        else
        {
            int l, r, m;
            cin >> l >> r >> m;
            cout << bit2.Get(l + m - 1, r) - bit2.Get(l - 1, r - m) << '\n';
        }
    }

    return 0;
}