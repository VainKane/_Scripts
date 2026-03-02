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

    void Update(int idx, int val)
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
int const BK = 2;
int bkId[N];

int n, m, q;

int a[N];
long long pre[N], f[N];

int lb[N], rb[N];

int cnt[BK + 5][N];
long long sum[BK + 5];
FenwickTree bit;

long long GetSum(int l, int r)
{
    if (l == 0) return pre[r];
    return pre[r] - pre[l - 1];
}

void Init()
{
    REP(i, n) bkId[i] = i / BK;
    REP(i, n)
    {
        cnt[bkId[i]][lb[i]]++;
        cnt[bkId[i]][rb[i] + 1]--;
    }

    REP(id, bkId[n - 1]) REP(i, n) cnt[id][i + 1] += cnt[id][i];

    pre[0] = a[0];
    FOR(i, 1, n - 1) pre[i] = pre[i - 1] + a[i];
    REP(i, n) f[i] = GetSum(lb[i], rb[i]);
    REP(i, n) sum[bkId[i]] += f[i];

    bit = FenwickTree(n);
}

void Update(int &pos, int val)
{
    bit.Update(pos + 1, val);
    FOR(i, 0, bkId[n - 1]) sum[i] += 1LL * val * cnt[i][pos];
}

long long Get(int l, int r)
{
    if (bkId[l] == bkId[r])
    {
        long long res = 0;
        FOR(i, l, r) res += f[i] + bit.Get(lb[i] + 1, rb[i] + 1);
        return res;
    }

    long long res = 0;

    FOR(i, bkId[l] + 1, bkId[r] - 1) res += sum[i];
    FOR(i, l, BK * (bkId[l] + 1) - 1) res += f[i] + bit.Get(lb[i] + 1, rb[i] + 1);
    FOR(i, BK * bkId[r], r) res += f[i] + bit.Get(lb[i] + 1, rb[i] + 1);

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) 
    {
        cin >> lb[i] >> rb[i];
        lb[i]--, rb[i]--;
    }

    Init();

    int q; cin >> q;
    while (q--)
    {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1)
        {
            x--;
            Update(x, y - a[x]);
            a[x] = y;
        }
        else cout << Get(x - 1, y - 1) << '\n';
    }
}