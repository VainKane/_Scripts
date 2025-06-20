#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = b; i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < n; i++)

long long a, b;
int k;

int n;
int x[20];
long long dp[20][2][10][170];

long long Get(long long val)
{
    n = 0;
    while (val)
    {
        x[n++] = val % 10;
        val /= 10;
    }

    reverse(x, x + n);

    memset(dp, 0, sizeof dp);
    dp[0][0][0][0] = 1;

    REP(i, n) FOR(r, 0, 1) FOR(digit, 0, 9) FOR(sum, 0, i * 9) 
    {
        int lim = r ? 9 : x[i];
        FOR(d, 0, lim) if ((digit + d) % k || i == 0 || sum == 0)  
            dp[i + 1][r | (d < lim)][d][sum + d] += dp[i][r][digit][sum];
    }

    long long res = 0;
    FOR(sum, 0, 9 * n) FOR(d, 0, 9) FOR(r, 0, 1)
        res += dp[n][r][d][sum];

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> k;
    cout << Get(b) - Get(a - 1);

    return 0;
}