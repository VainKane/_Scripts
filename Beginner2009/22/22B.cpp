#include <bits/stdc++.h>

using namespace std;

int const N = 10009;
int const M = 16;

int n;

int a[N][10];
long long dp[N][M + 10];
bool ok[M + 10];

int bit(int i, long long x)
{
    return (x >> i) & 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    memset(dp, -0x3f, sizeof dp);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
            dp[0][j] = 0;
        }
    }

    for (int x = 0; x < M; x++)
    {
        ok[x] = true;
        for (int i = 1; i < 4; i++)
        {
            if (bit(i, x) && bit(i - 1, x))
            {
                ok[x] = false;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int x = 0; x < M; x++)
        {
            for (int u = 0; u < M; u++)
            {
                if (!ok[u] || !ok[x]) continue;
                if ((u & x) != 0) continue;
                if (dp[i - 1][u] == -0x3f) continue;

                int s = 0;
                for (int k = 0; k < 4; k++)
                {
                    if (bit(k, x)) s += a[i][k];
                }
                
                dp[i][x] = max(dp[i][x], dp[i - 1][u] + s);
            }
        }
    }

    long long res = -1e18;
    for (int j = 0; j < M; j++)
    {
        res = max(res, dp[n][j]);
    }

    cout << res;

    return 0;
}