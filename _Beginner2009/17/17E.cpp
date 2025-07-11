#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second

int const N = 1009;
int const NMOD = 1;
int const MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277};
int const BASE = 256;

struct Hash
{
    int val[NMOD];

    Hash()
    {
        memset(val, 0, sizeof val);
    }

    bool operator == (Hash const other) const
    {
        REP(k, NMOD) if (val[k] != other.val[k]) return false;
        return true;
    }

    bool operator < (Hash const other) const
    {
        REP(k, NMOD) if (val[k] != other.val[k]) return val[k] < other.val[k];
        return false;
    }
};

int m, n;
int a, b;
char s[N][N];

int pw[NMOD][N * N];
int hs[NMOD][N][N];

map<Hash, int> mp;
vector<pair<int, int>> res;

int GetId(int i, int j)
{
    return (i - 1) * n + j;
}

void Init()
{
    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, m * n) pw[k][i] = (1ll * pw[k][i - 1] * BASE) % MOD[k]; 

        FOR(i, 1, m) FOR(j, 1, n) 
        {
            hs[k][i][j] = (hs[k][i - 1][j] + hs[k][i][j - 1]
                        - hs[k][i - 1][j - 1] + 1ll * s[i][j] * pw[k][GetId(i, j)]) % MOD[k]; 
            if (hs[k][i][j] < 0) hs[k][i][j] += MOD[k];
        }
    }
}

Hash Get(int i, int j, int u, int v)
{
    Hash res;

    REP(k, NMOD)
    {
        int tmp = (hs[k][u][v] - hs[k][u][j - 1] - hs[k][i - 1][v] + hs[k][i - 1][j - 1]) % MOD[k];
        if (tmp < 0) tmp += MOD[k];

        res.val[k] = (1ll * tmp * pw[k][m * n - GetId(i, j)]) % MOD[k];
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> s[i][j];
    cin >> a >> b;

    Init();

    int ma = 0;
    Hash hsMa;

    FOR(i, 1, m - a + 1) FOR(j, 1, n - b + 1)
    {
        Hash tmp = Get(i, j, i + a - 1, j + b - 1);
        int &x = mp[tmp];
        x++;

        if (mp[tmp] > ma)
        {
            ma = mp[tmp];
            hsMa = tmp;
        }
    }

    FOR(i, 1, m - a + 1) FOR(j, 1, n - b + 1)
    {
        if (Get(i, j, i + a - 1, j + b - 1) == hsMa) res.push_back({i, j});
    }

    cout << a << ' ' << b << '\n';
    FOR(i, res[0].F, res[0].F + a - 1)
    {
        FOR(j, res[0].S, res[0].S + b - 1) cout << s[i][j];
        cout << '\n';
    }

    cout << res.size() << '\n';
    for (auto p : res) cout << p.F << ' ' << p.S << '\n';

    // cout << Get(1, 4, 3, 6).val[0] << '\n' << Get(4, 3, 6, 5).val[0];
    // cout << " ma = " << ma;
    // cout << '\n';
    // for (auto p : mp) cout << p.S << ' ';

    return 0;
}