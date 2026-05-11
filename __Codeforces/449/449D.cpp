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

int const MOD = 1e9 + 7;
int const LOG = 20;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void Sub(int &x, int const &y)
{
    x -= y;
    if (x < MOD) x += MOD;
}

int n;
int cnt[MK(20) + 5];
int pw[MK(20) + 5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        cnt[x]++;
    }

    pw[0] = 1;
    FOR(i, 1, MK(20)) pw[i] = 2 * pw[i - 1] % MOD;

    int res = 0;

    REP(mask, 1e6)
    {
        int tmp = mask ^ (MK(LOG) - 1);

        int haha = 0;
        for (int s = tmp; s; s = (s - 1) & tmp)
            haha += cnt[s];
        Add(res, pw[haha]);
    }

    cout << res;

    return 0;
}