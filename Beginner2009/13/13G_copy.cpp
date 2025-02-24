#include <bits/stdc++.h>

using namespace std;

int n;
int k;

int l;
int r;

int d;
int a[5009];

long long dp[5009][5009];
long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    cin >> l >> r;
    cin >> d;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    memset(dp, -1, sizeof dp);

    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= l && a[i] <= r)
        {
            dp[i][1] = 0;
        }
    }

    for (int j = 2; j <= k; j++) 
    {
        for (int i = j; i <= n; i++)
        {
            if (j != k || (j == k && d - a[i] >= l && d - a[i] <= r))
            {
                for (int m = 1; m < i; m++)
                {
                    if (dp[m][j - 1] != -1)
                    {
                        if (j != 2 || (j == 2 && a[m] >= l && a[m] <= r))
                        {
                            if (a[i] - a[m] >= l && a[i] - a[m] <= r)
                            {
                                dp[i][j] = max(dp[i][j], dp[m][j - 1] + 2ll * (j - 1) * (k - j + 1) * (a[i] - a[m]));
                            }
                        }
                    }
                }
            }   
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cout << dp[i][j] << ' ';
        }

        cout << '\n';
    }

    for (int i = 1; i <= n; i++)
    {
        res = max(res, dp[i][k]);
    }

    cout << res;

    return 0;
}