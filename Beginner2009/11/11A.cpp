#include <bits/stdc++.h>

using namespace std;

int n;
int a[309];

int s = 0;
bool dp[309][(int)1e4 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (j == a[i])
            {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = dp[i - 1][j];

            if (j - a[i] >= 0)
            {
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - a[i]];
            }
        }
    }

    for (int j = 1; j <= s; j++)
    {
        if (dp[n][j]) cout << j << ' ';
    }

    return 0;
}