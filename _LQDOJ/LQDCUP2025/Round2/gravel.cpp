#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "gravel"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e3 + 5;
int const M = 3e5 + 5;
int const V = 1e5 + 5;

int n, m, p;

int r[N], y[N];

int t[M], g[M];
int v[M];

bool ft[N][V], fg[N][V];
bool ok[M];
bool solved[M];

int ma = 0;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= p) x -= p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> p;
    FOR(i, 1, n) cin >> r[i]; 
    FOR(i, 1, n) cin >> y[i];
    FOR(i, 1, m) cin >> t[i], maxi(ma, t[i]);
    FOR(i, 1, m) cin >> g[i], maxi(ma, g[i]);
    FOR(i, 1, m) cin >> v[i];

    FOR(i, 0, n) ft[i][0] = fg[i][0] = true;
    FOR(i, 1, n) FOR(j, 1, ma)
    {
        ft[i][j] = ft[i - 1][j];
        fg[i][j] = fg[i - 1][j];
        if (j >= r[i]) ft[i][j] |= ft[i - 1][j - r[i]];   
        if (j >= y[i]) fg[i][j] |= fg[i - 1][j - y[i]];
    }

    FOR(i, 1, m) ok[i] = (ft[n][t[i]] & fg[n][g[i]]);

    int res = 0;
    FOR(i, 1, m) 
    {
        int tmp = 1;

        FOR(j, i, m) 
        {
            if (!ok[j]) break;
            tmp = 1ll * tmp * v[j] % p;
            Add(res, tmp);
        }
    }

    cout << res;

    return 0;
}