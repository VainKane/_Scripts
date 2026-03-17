#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 314;

int m, n;
char a[N][N];

pair<int, bitset<N>> dp[N][N][N];

void Optimize(int x, int y, int k, int u, int v)
{
    if (v < 1 || v > n) return;
    if (a[u][v] == '*') return;

    int delta = 0;
    if (a[x][y] == '(') delta = -1;
    if (a[x][y] == ')') delta = 1;

    if (k + delta < 0) return;

    if (maxi(dp[x][y][k].F, dp[u][v][k + delta].F)) dp[x][y][k].S = dp[u][v][k + delta].S;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    FOR(i, 1, m) FOR(j, 1, n) FOR(k, 0, m) if (a[i][j] != 'M') dp[i][j][k] = "#";
    FORD(i, m - 1, 1) FOR(j, 1, n) FOR(k, 0, m)
    {
        Optimize(i, j, k, i + 1, j);
        Optimize(i, j, k, i + 1, j - 1);
        Optimize(i, j, k, i + 1, j + 1);
    }



    return 0;
}