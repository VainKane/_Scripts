#include <bits/stdc++.h>

using namespace std;

int n;
int a[25009];

long long dp[25009];
bool b[25009];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    dp[1] = 1ll * a[1];
    dp[2] = 1ll * a[1] + 1ll * a[2];
    dp[3] = 1ll * max(a[1], a[2]) + 1ll * a[3];

    memset(b, 1, sizeof b);

    for (int i = 3; i <= n; i++)
    {
        long long s1 = dp[i - 1];
        long long s2 = dp[i - 2] + 1ll * a[i];
        long long s3 = dp[i - 3] + 1ll * a[i - 1] + 1ll * a[i];

        if (dp[i] <= s1)
        {
            b[i] = 0;

            dp[i] = s1;
        }
        if (dp[i] <= s2)
        {
            b[i] = 1;
            b[i - 1] = 0;

            dp[i] = s2;
        }
        if (dp[i] <= s3)
        {
            b[i] = 1;
            b[i - 1] = 1;
            b[i - 2] = 0;

            dp[i] = s3;
        }
    }

    cout << dp[n] << '\n';

    for (int i = 1; i <= n; i++) cout << b[i] << ' ';
    cout << '\n';

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i])
        {
            cout << i << ' ';
            cnt++;
        }
        
        if (cnt == 10)
        {
            cout << '\n';
            cnt = 0;
        }
    }

    return 0;
}