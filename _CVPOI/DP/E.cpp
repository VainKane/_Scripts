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

struct State
{
    int x, y, k;
    char ch = '*';
};

int const N = 314;

int m, n;
char a[N][N];

int dp[N][N][N];
State trace[N][N][N];

void Optimize(int x, int y, int k, int u, int v)
{
    if (v < 1 || v > n) return;

    int val = a[x][y] == '.' ? 0 : 1;
    int delta = 0;

    if (a[x][y] == '(') delta = 1;
    if (a[x][y] == ')') delta = -1;

    if (k + delta < 0) return;

    int haha = dp[u][v][k + delta] + val;
    auto &p = trace[x][y][k];

    // char ch = a[x][y] == '.' ? trace[u][v][k + delta].ch : a[x][y];
    char traceCh = a[u][v] == '.' ? trace[u][v][k + delta].ch : a[u][v];

    // if (x == 8 && y == 1 && k == 0 && u == 7 && v == 1) 
    // {
    //     cout << trace[u][v][k + delta].ch << ' ' << p.ch << '\n';
    //     cout << p.x << ' ' << p.y;
    // }

    if (maxi(dp[x][y][k], haha)) p = {u, v, k + delta, traceCh};
    else if (dp[x][y][k] == haha && traceCh < p.ch) p = {u, v, k + delta, traceCh};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    memset(dp, -0x3f, sizeof dp);

    FOR(j, 1, n) dp[0][j][0] = 0;
    FOR(i, 1, m) FOR(j, 1, m) if (a[i][j] == '*') dp[i][j][0] = 0;

    FOR(i, 1, m) FOR(j, 1, n) FOR(k, 0, i) if (a[i][j] != '*')
    {
        Optimize(i, j, k, i - 1, j);
        Optimize(i, j, k, i - 1, j - 1);
        Optimize(i, j, k, i - 1, j + 1);
    }

    FOR(j, 1, n) if (a[m][j] == 'M')
    {
        auto p = trace[m][j][0];
        string res = "";
        while (p.x && p.y)
        {
            if (a[p.x][p.y] == '(' || a[p.x][p.y] == ')') res += a[p.x][p.y];
            p = trace[p.x][p.y][p.k];
        }

        cout << sz(res) << '\n' << res;
    }

    // cout << dp[4][2][0];
    // cout << dp[6][1][0];
    // cout << trace[5][1][0].ch;

    // cout << dp[1][7][1];

    // cout << trace[7][1][1].ch << ' ' << trace[7][2][1].ch;
    // cout << trace[8][1][1].x << ' ' << trace[8][1][1].y;

    // cout << trace[7][1][1].ch;

    return 0;
}