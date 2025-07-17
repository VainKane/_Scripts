#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define ID(i, j, n) ((i - 1) * (n) + (j))
#define sz(v) ((int)(v).size())
#define F first
#define S second

const int N = 1010;
const int NMOD = 1;
const int MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};
const int BASE = 256;

struct Hash 
{
    int val[NMOD];

    Hash() 
    { 
        memset(val, 0, sizeof val); 
    }

    bool operator == (const Hash &other) const 
    {
        REP(k, NMOD) if (val[k] != other.val[k]) return false;
        return true;
    }

    bool operator < (const Hash &other) const 
    {
        REP(k, NMOD) if (val[k] != other.val[k]) return val[k] < other.val[k];
        return false;
    }
};

int m, n;
int a, b;
char s[N][N];

int pw[NMOD][N * N + 5];
int hs[NMOD][N][N];

map<Hash,vector<pair<int,int>>> mp;

int MAX;

void Init() 
{
    MAX = N * N;
    
    REP(k, NMOD) 
    {
        pw[k][0] = 1;
        FOR(i, 1, MAX) pw[k][i] = (1ll * pw[k][i - 1] * BASE) % MOD[k];

        FOR(i, 1, m) FOR(j, 1, n)
            hs[k][i][j] = (hs[k][i - 1][j] + hs[k][i][j - 1]
                - hs[k][i - 1][j - 1] + 1ll * s[i][j] * pw[k][ID(i, j, n)] + MOD[k]) % MOD[k];
    }
}

Hash Get(int i, int j, int u, int v) 
{
    Hash res;
    if (i > u || j > v) return res;
    
    REP(k, NMOD) 
    {
        int tmp = (hs[k][u][v] - hs[k][u][j - 1] - hs[k][i - 1][v] + hs[k][i - 1][j - 1]) % MOD[k];
        if (tmp < 0) tmp += MOD[k];

        res.val[k] = (1ll * tmp * pw[k][MAX - ID(i, j, n)]) % MOD[k];
    }

    return res;
}

int main() 
{
    scanf("%d%d", &m, &n);
    getchar();

    FOR(i, 1, m) fgets(s[i] + 1, n + 2, stdin);
    scanf("%d%d", &a, &b);

    Init();

    int ma = -1;
    Hash hsMa;

    // if (m >= 700 && n >= 700) return 0;

    FOR(i, 1, m - a + 1) FOR(j, 1, n - b + 1) 
    {
        Hash tmp = Get(i, j, i + a - 1, j + b - 1);
       
        auto &v = mp[tmp];
        v.push_back({i, j});
        
        if (sz(v) > ma) 
        {
            ma = sz(v);
            hsMa = tmp;
        }
    }

    auto &res = mp[hsMa];

    printf("%d %d\n", a, b);
    
    FOR(i, res[0].F, res[0].F + a - 1) 
    {
        FOR(j, res[0].S, res[0].S + b - 1) putchar(s[i][j]);
        putchar('\n');
    }

    printf("%d\n", ma);
    for (auto &p : res) printf("%d %d\n", p.F, p.S);
    
    return 0;
}