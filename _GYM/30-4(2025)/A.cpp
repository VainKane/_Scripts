#include <bits/stdc++.h>

using namespace std;

int const N = 2029;

int n, m;
int a[N][N];

long long dp[N][N][3];
long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    dp[1][1][0] = a[1][1];

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < 3; k++) 
            {
                if (!dp[i][j][k]) continue;
                
                dp[i][j + 1][0] = max(dp[i][j + 1][0], dp[i][j][k] + a[i][j + 1]);
                if (k < 2) dp[i + 1][j][k + 1] = dp[i][j][k] + a[i + 1][j];
            }
        }
    }

    for (int k = 0; k < 3; k++)
    {
        res = max(res, dp[m][n][k]);
    }

    cout << res;

    return 0;
}