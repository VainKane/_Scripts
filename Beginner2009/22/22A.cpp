#include <bits/stdc++.h>

using namespace std;

int const N = 29;

int n;
int a[N][N];
long long dp[(1 << 20) + 10];

int Bit(int i, int x)
{
    return (x >> i) & 1;
}

int TurnOff(int i, int x)
{
    return x & (~(1 << i));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int x = 1; x < (1 << n); x++)
    {
        int k = __builtin_popcountll(x);
        for (int i = 0; i < n; i++)
        {
            if (Bit(i, x))
            {
                dp[x] = max(dp[x], dp[TurnOff(i, x)] + a[i][k]);
            }
        }
    }

    cout << dp[(1 << n) - 1];

    return 0;
}