#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;
int const BASE = 256;
int const NMOD = 2;
int const MODS[] = {(int)1e9 + 2277, (int)1e9 + 5277};

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
};

int n;

string s1, s2;
pair<int, int> res;

int pw[NMOD][N];
int hs1[NMOD][N];
int hs2[NMOD][N];

void Init()
{
    s2 = s1;
    reverse(all(s2));

    n = s1.size();
    s1 = " " + s1;
    s2 = " " + s2;

    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, n) 
        {
            pw[k][i] = 1ll * pw[k][i - 1] * BASE % MODS[k];
            hs1[k][i] = (hs1[k][i - 1] + 1ll * s1[i] * pw[k][i - 1]) % MODS[k];
            hs2[k][i] = (hs2[k][i - 1] + 1ll * s2[i] * pw[k][i - 1]) % MODS[k];
        }
    }
}

Hash GetHash(int l, int r, int hs[NMOD][N])
{
    Hash res;

    REP(k, NMOD)
    {
        int tmp = hs[k][r] - hs[k][l - 1];
        if (tmp < 0) tmp += MODS[k];

        res.val[k] = 1ll * tmp * pw[k][n - l + 1] % MODS[k];
    }

    return res;
}

int GetPos(int len)
{
    FOR(l, 1, n - len + 1)
    {
        int r = l + len - 1;
        if (GetHash(l, r, hs1) == GetHash(n - r + 1, n - l + 1, hs2)) return l;
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s1;
    Init();

    FORD(len, n, 1) 
    {
        int pos = GetPos(len);
        if (pos) 
        {
            FOR(i, pos, pos + len - 1)  cout << s1[i];
            return 0;
        }
    }

    return 0;
}