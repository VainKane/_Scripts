#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 3e4 + 5;
int const oo = 3e4;

int n, d;

int a[N];
int dp[N][255];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;
    FOR(i, 1, n)
    {
        int p; cin >> p;
        a[p]++;
    }

    memset(dp, -1, sizeof dp);
    dp[d] = a[d];
    int res = 0;

    FOR(i, d, oo) FOR(j, d - 245, d + 245) if (dp[i][j] != -1)
    {
        maxi(res, dp[i]);
        FOR(k, max(j - 1, 1), min(j + 1, oo - i))
            maxi(dp[i + k][k], dp[i][j] + a[i + k]);
    }
    
    cout << res;

    return 0;
}