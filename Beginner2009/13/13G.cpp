#include <bits/stdc++.h>

using namespace std;

int n;
int k;

int l;
int r;

int sg;
int a[5009];

long long dp[5009][5009];
long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    cin >> l >> r;
    cin >> sg;

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
        deque<int> qu;
        long long d = 2 * (j - 1) * (k - j + 1);

        for (int i = 1; i <= n; i++)
        {
            if (j == k && (sg - a[i] < l || sg - a[i] > r)) continue;

            while (!qu.empty() && (a[i] - a[qu.front()] > r || a[i] - a[qu.front()] < l)) qu.pop_front();
            while (!qu.empty() && j == 2 && (a[qu.front()] < l || a[qu.front()] > r)) qu.pop_front();
            while (!qu.empty() && dp[qu.front()][j - 1] == -1) qu.pop_front();
            while (!qu.empty() && dp[qu.back()][j - 1] - d * a[qu.back()] <= dp[i][j - 1] - d * a[i]) qu.pop_back();

            qu.push_back(i);
            dp[i][j] = dp[qu.front()][j - 1] + d * (a[i] - a[qu.front()]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        res = max(res, dp[i][k]);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << res;

    return 0;
}