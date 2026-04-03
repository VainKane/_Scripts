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

int const N = 1e5 + 5;
long long const oo = 1e18;

int n;
int h[N];

vector<int> vals;
int haha[N], hehe[N];

FenwickTree bitL, bitR;

void Compress()
{
    FOR(i, 1, n)
    {
        vals.push_back(haha[i] = h[i] - i);
        vals.push_back(hehe[i] = h[i] + i);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n)
    {
        haha[i] = lower_bound(all(vals), haha[i]) - vals.begin() + 1;
        hehe[i] = lower_bound(all(vals), hehe[i]) - vals.begin() + 1;
    }

    bitL = bitR = FenwickTree(sz(vals));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> h[i];

    Compress();
    FOR(i, 1, n) bitR.Update(hehe[i], 1);

    long long res = oo;

    FOR(i, 1, n)
    {
        bitR.Update(hehe[i], -1);
        bitL.Update(haha[i], 1);

        int l = 1;
        int r = 1e9 + n;
        int med = r;

        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (bitL.Get(upper_bound(all(vals), mid - i)) +
                bitR.Get(upper_bound(all(vals), mid + i)) >= (n + 1) / 2)
            {
                med = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }


    }

    cout << res;

    return 0;
}