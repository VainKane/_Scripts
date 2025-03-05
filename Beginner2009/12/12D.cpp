#include <bits/stdc++.h>

using namespace std;

int n;
int a[109];

int dp[109][109];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int mi = a[1] * a[2] * a[3];
    for (int j = 2; j <= n - 1; j++)
    {
        mi = min(mi, a[j] * a[j - 1] * a[j + 1]);
        dp[1][j] = mi;
    }

    for (int i = 2; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            dp[i][j] = INT_MAX;

            for (int u = i; u <= j; u++)
            {
                for (int v = u + 1; v <= j; v++)
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][u] + a[v] * a[v - 1] * a[v + 1]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dp[i][j] << ' ';
        }

        cout << '\n';
    }

    cout << dp[n - 1][n - 2];

    return 0;
}