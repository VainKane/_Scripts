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

int const N = 1009;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int m, n;

int dp[N][MK(10) + 5];
vector<int> valid;
vector<int> adj[MK(10) + 5];

bool Check(int mask)
{
    int last = __builtin_ctz(mask & -mask);
    for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp);
        if ((i - last) & 1) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;

    REP(mask, MK(m)) if (Check(mask)) valid.push_back(mask);
    for (auto &mask1 : valid) for (auto &mask2 : valid) if (Check(mask1 | mask2)) adj[mask1].push_back(mask2);

    dp[0] = 1;
    REP(i, n) for (auto &mask : valid) for (auto &nxt : adj[mask])
        Add(dp[i + 1][nxt], dp[i][mask]);

    return 0;
}