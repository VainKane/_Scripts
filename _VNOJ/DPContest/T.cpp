#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 3009;
int const MOD = 1e9 + 7;

int n;
string s;

int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;
    s = " " + s;

    FOR(i, 1, n) dp[1][i] = 1;

    FOR(i, 2, n) FOR(j, 1, n)
    {
        if (s[i - 1] == '<') FOR(p, 1, j - 1) dp[i][j] += dp[i - 1][p];
        else FOR(p, j + 1, n) dp[i][j] += dp[i - 1][p];
    }

    int res = 0;
    FOR(j, 1, n) cout << j << ' ' << dp[3][j] << '\n';
    cout << res;  

    return 0;
}