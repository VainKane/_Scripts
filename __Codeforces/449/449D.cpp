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

int const LOG = 22;
int const MOD = 1e9 + 7;

int n;
int f[MK(20) + 5][LOG];
int pw[LOG];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        f[x][0]++;
    }

    FORD(x, 1e6, 0) REP(i, 20)
    {
        if (BIT(i, x)) f[x][i + 1] = f[x][i];
        else f[x][i + 1] = (f[x][i] + f[x | MK(i)][i]) % MOD;
    }

    pw[0] = 1;
    FOR(i, 1, 20) pw[i] = 2 * pw[i - 1] % MOD;

    int res = 0;
    FOR(mask, 0, 0)
    {
        int cnt = __builtin_popcount(mask);
        int delta = (cnt & 1) ? -1 : 1;
        res = (res + 1LL * delta * f[mask][20] * (pw[cnt] + MOD)) % MOD;
    }

    cout << res;

    return 0;
}