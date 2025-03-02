#include <bits/stdc++.h>

using namespace std;

int n;

int a[3009];
int b[3009];
int dp[3009][3000 * 6 + 10];

int s = 0;
int sum = 0;

int res = INT_MAX;
vector<int> mark;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;

    memset(dp, -1, sizeof dp);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        s += max(a[i], b[i]);
        sum += a[i] + b[i];
    }

    dp[1][a[1]] = 0;
    dp[1][b[1]] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (j >= a[i] && dp[i - 1][j - a[i]] != -1)
            {
                dp[i][j] = dp[i - 1][j - a[i]];
            }
            if (j >= b[i] && dp[i - 1][j - b[i]] != -1)
            {
                dp[i][j] = dp[i - 1][j - b[i]] + 1;
            }
            if (j >= a[i] && j >= b[i] && dp[i - 1][j - a[i]] != -1 && dp[i - 1][j - b[i]] != -1)
            {
                dp[i][j] = min(dp[i - 1][j - a[i]], dp[i - 1][j - b[i]] + 1);
            }
        }
    }

    int k;

    for (int j = 1; j <= s; j++)
    {
        if (dp[n][j] != -1)
        {
            if (res > abs(j - (sum - j)))
            {
                k = j;
                res = abs(j - (sum - j));
            }
        }
    }

    for (int i = n; i >= 1; i--)
    {
        if (k < a[i] && k < b[i]) break;
        if (k >= b[i] && dp[i - 1][k - b[i]] != -1)
        {
            if (dp[i - 1][k - a[i]] == -1 || dp[i - 1][k - b[i]] < dp[i - 1][k - a[i]])
            {
                mark.push_back(i);
                k -= b[i];
            }
            else if (dp[i - 1][k - a[i]] != -1) k -= a[i];
        }
        else if (dp[i - 1][k - a[i]] != -1) k -= a[i];
    }
    
    cout << res << '\n';    
    cout << mark.size() << '\n';
    for (auto val : mark) cout << val << '\n';
    
    return 0;
}