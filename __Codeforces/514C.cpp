#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(v) ((int)v.size())

int const N = 3e5 + 5;
int const BASE = 256;
int const NMOD = 2;
int const MODS[] = {(int)1e9 + 2277, (int)1e9 + 5277};

struct Hash
{
    int x[NMOD];

    Hash()
    {
        memset(x, 0, sizeof x);
    }

    bool operator < (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return x[k] < other.x[k];
        return false;
    }

    bool operator == (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return false;
        return true;
    }
};

int pw[NMOD][N];

void Init()
{
    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, 3e5) pw[k][i] = 1ll * pw[k][i - 1] * BASE % MODS[k];
    }
}

Hash GetHs(string s)
{
    Hash hs;

    int n = sz(s);
    s = " " + s;

    REP(k, NMOD) 
    {
        FOR(i, 1, n)
            hs.x[k] = (hs.x[k] + 1ll * s[i] * pw[k][i - 1]) % MODS[k];
        hs.x[k] = 1ll * hs.x[k] * pw[k][n] % MODS[k];
    }

    return hs;
}

int n, m;
Hash a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Init();

    cin >> n >> m;
    FOR(i, 1, n)
    {
        string s; cin >> s;
        a[i] = GetHs(s);
    }

    sort(a + 1, a + n + 1);

    while (m--)
    {
        string s; cin >> s;
        
    }

    return 0;
}