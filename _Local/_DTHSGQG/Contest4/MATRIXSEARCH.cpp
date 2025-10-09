#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

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
        while (idx)
        {
            bit[idx] += val;
            idx ^= idx & -idx;
        }
    }

    int Get(int idx)
    {
        int res = 0;

        
    }
};

int const N = 1009;

int m, n;
int a[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    int q; cin >> q;
    while (q--)
    {
        
    }

    return 0;
}