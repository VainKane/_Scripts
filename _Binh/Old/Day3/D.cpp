#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

struct FenwickTree
{
    vector<long long> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n; 
        bit.resize(n + 5);
    }

    void Update(int idx, long long val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    void Update(int l, int r, long long val)
    {
        if (l > r) return;
        Update(l, val);
        Update(r + 1, -val);
    }

    long long GetSum(int idx)
    {
        long long res = 0;
        while (idx)
        {
            res += bit[idx];
            idx ^= idx & -idx;
        }
        return res;
    }

    long long GetSum(int l, int r)
    {
        if (l > r) return 0;
        return GetSum(r) - GetSum(l - 1);
    }
};

int const N = 1e5 + 5;

int n, q;
int a[N];
int l[N], r[N];

FenwickTree bitF;
FenwickTree bitSum;

void Init()
{
    bitF = bitSum = FenwickTree(n);
    FOR(i, 1, n)
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> l[i] >> r[i];

    while (q--)
    {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1)
        {
            
        }
    }

    return 0;
}