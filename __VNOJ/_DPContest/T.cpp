#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 3009;
int const MOD = 1e9 + 7;

int n;
int dp[N][N];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    dp[1][1] = 1;

    cin >> n;
    FOR(i, 2, n)
    {
        char ch; cin >> ch;
        FOR(j, 1, i)
        {
            if (ch == '<') Add(dp[i][j], dp[i - 1][j - 1]);
            else dp[i][j] = (dp[i - 1][i - 1] - dp[i - 1][j - 1] + MOD) % MOD;
        }
        FOR(j, 1, i) Add(dp[i][j], dp[i][j - 1]);
    }

    cout << dp[n][n];

    return 0;
}