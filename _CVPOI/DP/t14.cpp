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

long long a, b;

long long dp[20][2][12][12];

bool Check(int x)
{
    vector<int> digits;

    while (x)
    {
        digits.push_back(x % 10);
        x /= 10;
    }

    REP(i, sz(digits))
    {
        if (i > 0 && digits[i] == digits[i - 1]) return false;
        if (i > 1 && digits[i] == digits[i - 2]) return false;
    }

    return true;
}

long long Get(long long x)
{
    if (x < 100)
    {
        int res = 0;
        FOR(i, 1, x) res += Check(i);
        return res;
    }

    vector<int> digits;

    while (x)
    {
        digits.push_back(x % 10);
        x /= 10;
    }

    reverse(all(digits));
    int n = sz(digits);

    memset(dp, 0, sizeof dp);
    FOR(pre, 0, digits[0])
    {
        int lim = pre < digits[0] ? 9 : digits[1];
        FOR(cur, 0, lim) if (cur != pre) dp[2][pre < digits[0] || cur < digits[1]][cur][pre] = 1;
    }

    FOR(i, 2, n - 1) REP(r, 2) FOR(cur, 0, 9) FOR(pre, 0, 9) if (dp[i][r][cur][pre])
    {
        int lim = r ? 9 : digits[i];
        FOR(d, 0, lim) if (d != cur && d != pre) dp[i + 1][r | (d < lim)][d][cur] += dp[i][r][cur][pre];
    }

    long long res = 0;
    REP(r, 2) FOR(cur, 0, 9) FOR(pre, 0, 9) res += dp[n][r][cur][pre];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;
    cout << Get(b) - Get(a - 1);

    return 0;
}