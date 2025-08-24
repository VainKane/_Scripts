#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = b; i <= _b; i++)

int const N = 1e4 + 5;
int const MOD = 1e9 + 7;

string k;
int D;

int n;
int x[N];
int dp[N][2][109];

void Add(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int F(int idx, bool smaller, int sum)
{
    if (idx < 0) return sum == 0;

    int &res = dp[idx][smaller][sum];
    if (res != -1) return res;

    res = 0;
    
    int lim = smaller ? 9 : x[idx];
    FOR(d, 0, lim) Add(res, F(idx - 1, smaller | (d < lim), (sum + d) % D));

    return res;
}

int Get(string k)
{
    n = 0;
    for (int i = k.size() - 1; i >= 0; i--)
    {
        x[n++] = k[i] - '0';
    }

    memset(dp, -1, sizeof dp);
    return F(n - 1, 0, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> k >> D;
    cout << (Get(k) - 1 + MOD) % MOD;

    return 0;
}