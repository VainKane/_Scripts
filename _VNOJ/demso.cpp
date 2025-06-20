#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < n; i++)

int const N = 17;

long long a, b;
int D, k;

int digits[N];
long long dp[N][2][11][N];

long long Get(long long x)
{
    int n = 0;
    while (x)
    {
        digits[n++] = x % 10;
        x /= 10;
    }

    reverse(digits, digits + n);
    k = min(k, max(n - 1, 0));

    memset(dp, 0, sizeof dp);
    FOR(d, 0, min(9ll, x)) dp[1][d < x][d][0] = 1;
    dp[0][0][0][0] = 1;

    REP(i, n) FOR(r, 0, 1) FOR(digit, 0, 9) FOR(cnt, 0, k) if (dp[i][r][digit][cnt])
    {
        int lim = r ? 9 : digits[i];
        FOR(d, 0, lim) dp[i + 1][r | (d < lim)][d][cnt + ((abs(digit - d) <= D) && i)] += dp[i][r][digit][cnt];
    }
    
    long long res = 0;
    FOR(r, 0, 1) FOR(d, 0, 9) FOR(cnt, 0, k) res += dp[n][r][d][cnt];

    return res; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> D >> k;
    cout << Get(b) - Get(a - 1);

    return 0;
}