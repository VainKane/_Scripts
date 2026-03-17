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

string dp[N][N][N];

void Optimize(int x, int y, int k, int u, int v)
{
    if (v < 1 || v > n) return;
    if (a[u][v] == '*') return;

    int delta = 0;
    if (a[x][y] == '(') delta = -1;
    if (a[x][y] == ')') delta = 1;

    if (k + delta < 0) return;
    if (dp[u][v][k + delta] == "#") return;
 
    string s = dp[u][v][k + delta];
    if (a[x][y] != '.' && a[x][y] != '*') s += a[x][y];

    if (sz(dp[x][y][k]) < sz(s) || dp[x][y][k] == "#") dp[x][y][k] = s;
    else if (sz(dp[x][y][k]) == sz(s)) mini(dp[x][y][k], s);
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

    string res = "";

    FOR(i, 1, m) FOR(j, 1, n) if (i == 1 || a[i][j] == '*')
    {
        if (sz(dp[i][j][0]) > sz(res)) 
        {
            res = dp[i][j][0];
            cout << i << ' ' << j << ' ' << res << '\n';
        }
        // else if (sz(dp[i][j][0]) == sz(res)) mini(res, dp[i][j][0]);
    }

    // cout << sz(res) << '\n' << res;

    return 0;
}