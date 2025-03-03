#include <bits/stdc++.h>

using namespace std;

int n;
int k;

int a[109];
int pre[109];

long double dp[109][109];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
                        
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

    return 0;
}