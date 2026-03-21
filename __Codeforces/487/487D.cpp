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

int const N = 1e5 + 5;
int const M = 14;
int const BK = 2; // HAY UUU, PLZ REMEMBER TO SET BK BACK TO 314, OTHERWISE...
int const GR = N * M / BK + 5;

int bkId[N][M];

int const dx[] = {-1, 0, 1, 0};
int const dy[] = {0, 1, 0, -1};
int dir[256];

int m, n, q;
char a[N][M];

pair<int, int> pos[N][M];
bool visited[N][M];

int GetId(int i, int j)
{
    return (i - 1) * m + j;
}

bool Inside(int x, int y)
{
    return  x >= 1 && x <= m &&
            y >= 1 && y <= n;
}

void Build(int x, int y)
{
    auto &p = pos[x][y] = {x, y};
    int id = bkId[x][y];

    int cnt = 0;
    while (Inside(p.F, p.S) && bkId[p.F][p.S] == id && cnt <= BK + 20)
    {
        cnt++;
        int i = dir[a[p.F][p.S]];
        p.F += dx[i], p.S += dy[i];
    }
}

void Init()
{
    FOR(i, 1, m) FOR(j, 1, n) bkId[i][j] = (GetId(i, j) - 1) / BK + 1;
    dir['>'] = 1, dir['<'] = 3;
    FOR(i, 1, m) FOR(j, 1, n) Build(i, j);
}

pair<int, int> Get(int x, int y)
{
    auto &p = pos[x][y];

    FOR(haha, 1, GR) p = pos[x][y];
    if (Inside(p.F, p.S)) p = {-1, -1};
    return p;
}

void Update(int xs, int ys)
{
    Build(xs, ys);

    vector<pair<int, int>> used;
    queue<pair<int, int>> q;

    used.push_back({xs, ys});
    visited[xs][ys] = true;
    q.push({xs, ys});

    while (!q.empty())
    {
        int x = q.front().F;
        int y = q.front().S;
        q.pop();

        pos[x][y] = pos[xs][ys];

        REP(i, 4)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (bkId[u][v] != bkId[xs][ys] || visited[u][v]) continue;
            if (u + dx[dir[a[u][v]]] != x || v + dy[dir[a[u][v]]] != y) continue;

            used.push_back({u, v});
            visited[u][v] = true;
            q.push({u, v});
        }
    }

    for (auto &p : used) visited[p.F][p.S] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> q;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    Init();

    while (q--)
    {
        char type, c;
        int x, y;

        cin >> type >> x >> y;
        if (type == 'A')
        {
            auto p = Get(x, y);
            cout << p.F << ' ' << p.S << '\n';
        }
        else
        {
            cin >> c;
            a[x][y] = c;
            Update(x, y);
        }
    }

    return 0;
}