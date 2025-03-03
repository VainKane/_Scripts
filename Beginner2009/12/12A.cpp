#include <bits/stdc++.h>

using namespace std;

int m;
int n;

int a[109][109];
int dp[109][109];

int res = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;

    memset(dp, 0x3f, sizeof dp);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
        dp[i][1] = a[i][1];
    }

    dp[1][0] = 0;
    for (int j = 1; j <= n; j++)
    {
        dp[1][j] = dp[1][j - 1] + a[1][j];
    }

    for (int i = 2; i <= m; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            if (i != 1 || j != 1)
            {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i + 1][j - 1]}) + a[i][j];
            }
        }
    }    

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << res;

    return 0;
}