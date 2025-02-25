#include <bits/stdc++.h>

using namespace std;

int n, k, l, r, d;
int a[5009];
long long dp[5009][5009];
long long res = 0;
deque<int> q;

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
            q.push_back(i);
            dp[i][1] = 0;
        }
    }

    for (int j = 2; j <= k; j++)
    {
        if (j != 2)
        {
            q.clear();
        }

        for (int i = j; i <= n; i++)
        {
            // if (j != k || (j == k && (d - a[i] >= l && d - a[i] <= r)))
            {
                while (!q.empty() && (a[i] - a[q.front()] > r || a[i] - a[q.front()] < l))
                {
                    q.pop_front();
                }
                while (!q.empty() && j == 2 && (a[q.front()] > r || a[q.front()] < l))
                {
                    q.pop_front();
                }
                while (!q.empty() && dp[q.front()][j - 1] == -1)
                {
                    q.pop_front();
                }
                while (!q.empty() && dp[q.back()][j - 1] == -1)
                {
                    q.pop_back();
                }
                while (!q.empty() && dp[q.back()][j - 1] + 2ll * (j - 1) * (k - j + 1) * (a[i] - a[q.back()]) < dp[i][j - 1])
                {
                    q.pop_back();
                }
                
                q.push_back(i);
                if (j != k || (j == k && (d - a[i] >= l && d - a[i] <= r)))
                {
                    if (q.front() < i)
                    {
                        dp[i][j] = dp[q.front()][j - 1] + 2ll * (j - 1) * (k - j + 1) * (a[i] - a[q.front()]);
                    }
                }
               
            }
        }
    }   

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= k; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }

    //     cout << '\n';
    // }

    for (int i = 1; i <= n; i++)
    {
        res = max(res, dp[i][k]);
    }

    cout << res;

    return 0;
}