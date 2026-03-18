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

int const N = 707;
int const oo = 1e9;
int const dx[] = {-1, 0, 1, 0};
int const dy[] = {0, 1, 0, -1}; 

int n;

int h[N][N], v[N][N];
map<double, bool> visited[N][N];

int cnt = 0;

bool Inside(int x, int y)
{
    return  x >= 1 && x <= n &&
            y >= 1 && y <= n;
}

void DFS(int i, int j, double t)
{
    visited[i][j][t] = true;
    cnt++;

    REP(dir, 4)
    {
        int x = i + dx[dir];
        int y = j + dy[dir];

        double haha = (h[x][y] - h[i][j]) / (double)(v[i][j] - v[x][y]);
        if (!Inside(x, y) || visited[x][y][t]) continue;
        if ((t == oo && h[i][j] != h[x][y]) || (t != oo && haha != t)) continue;
    
        DFS(x, y, t);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> h[i][j];
    FOR(i, 1, n) FOR(j, 1, n) cin >> v[i][j];

    int res = 0;

    FOR(i, 1, n) FOR(j, 1, n) REP(dir, 4)
    {
        int x = i + dx[dir];
        int y = j + dy[dir];

        // if (v[i][j] == v[x][y]) continue;
        double t = v[i][j] == v[x][y] ? oo : (h[x][y] - h[i][j]) / (double)(v[i][j] - v[x][y]);
        if (t < 0 || !Inside(x, y) || visited[x][y][t]) continue;

        cnt = 0;
        DFS(i, j, t);
        maxi(res, cnt);
    }

    cout << res;

    return 0;
}