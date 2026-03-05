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

int const N = 800;

int m, n;
int a[N][N];

int ccId[N][N];
int h[N * N];
int cc = 0;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void BFS(int xs, int ys)
{
    queue<pair<int, int>> q;
    q.push({xs, ys});
    ccId[xs][ys] = cc;

    while (!q.empty())
    {
        int x = q.front().F;
        int y = q.front().S;
        q.pop();

        REP(i, 4)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (ccId[u][v] == cc) continue;
            if (a[u][v] != a[xs][ys]) mini(h[cc], a[u][v]);
            else
            {
                ccId[u][v] = cc;
                q.push({u, v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(a, -1, sizeof a);
    memset(h, 0x3f, sizeof h);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    FOR(i, 1, m) FOR(j, 1, n) if (!ccId[i][j])
    {
        cc++;
        BFS(i, j);
    }

    long long res = 0;
    FOR(i, 1, m) FOR(j, 1, n) res += max(0, h[ccId[i][j]] - a[i][j]);
    cout << res;

    // cout << "--------------------\n";
    // FOR(i, 1, m)
    // {
    //     FOR(j, 1, n) cout << ccId[i][j] << ' ';
    //     cout << '\n';
    // }

    return 0;
}