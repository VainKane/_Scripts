#include <bits/stdc++.h>

using namespace std;

int n;

int a[10009];
bool dp[1009][10009];

int s = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
        dp[i][0] = 1;
    }

    sort(a + 1, a + n + 1, greater<int> ());

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            dp[i][j] = d[i - 1][j];
            if (j >= a[i])
            {
                dp[i][j] = dp[i][j] | dp[i - 1][j - a[i]];
            }

            if (dp[i][j])
            {
                if (j * 2 > s)
            }
        }
    }

    return 0;
}