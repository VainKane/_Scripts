#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define MK(i) (1 << (i))
#define BIT(i, x) (((x) >> (i)) & 1)
#define name "23on2b3"

int Get(int x, int r)
{
    int k = 32 - __builtin_clz(x);
    
    int res = r >= x;
    int tmp = x;
    REP(i, 31 - k) if (BIT(i + k, r))
    {
        tmp |= MK(i);
        res += r >= tmp;
    }
    
    for (int haha = (MK(k) - 1) ^ x; haha; haha ^= haha & -haha)
    {
        int i = __builtin_ctz(haha & -haha);
        x |= MK(i);
        res += r >= x;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    int q; cin >> q;
    while (q--)
    {
        int a, l, r;
        cin >> a >> l >> r;
        cout << Get(a, r) << " " << Get(a, l - 1) << '\n';
        cout << Get(a, r) - Get(a, l - 1) << '\n';
    }

    return 0;
}