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

int dp[N][N][N];
pair<int, int> trace[N][N];

void Optimize(int x, int y, int k, int u, int v, int delta, int val)
{
    if (k + delta < 0) return;

    int haha = dp[u][v][k + delta] + val;
    auto &p = trace[x][y];

    if (maxi(dp[x][y][k], haha)) p = {u, v};
    else if (dp[x][y][k] == haha && a[u][v] < a[p.F][p.S]) p = {u, v};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(a, '*', sizeof a);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    memset(dp, -0x3f, sizeof dp);
    FOR(j, 1, n) if (a[m][j] == 'M') dp[m][j][0] = 0;

    FORD(i, m - 1, 1) FOR(j, 1, n) FOR(k, 0, m) if (a[i][j] != '*')
    {
        int delta = 0;
        int val = (a[i][j] != '*' && a[i][j] != '.') ? 1 : 0;

        if (a[i][j] == '(') delta = -1;
        if (a[i][j] == ')') delta = 1;
        
        Optimize(i, j, k, i + 1, j, delta, val);
        Optimize(i, j, k, i + 1, j - 1, delta, val);
        Optimize(i, j, k, i + 1, j + 1, delta, val);
    }

    int x = 0, y = 0;

    FOR(i, 1, m) FOR(j, 1, n)
    {
        if (dp[x][y][0] < dp[i][j][0]) x = i, y = j;
        else if (dp[x][y][0] == dp[i][j][0] && a[x][y] > a[i][j]) x = i, y = j;
    }

    // string res = "";
    // while (x && y)
    // {
    //     if (a[x][y] != '.') res += a[x][y];
    //     pair<int, int> p = trace[x][y];
    //     x = p.F, y = p.S;
    // }

    // reverse(all(res));
    // cout << sz(res) << '\n' << res;

    cout << dp[1][1][0];

    return 0;
}