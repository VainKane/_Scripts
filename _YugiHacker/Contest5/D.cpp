#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "farming"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const MOD = 1e9 + 7;
int const N = 260;

int m, n, k;

vector<int> v;
vector<int> valid[MK(16)];

vector<vector<int>> dp[2][N];
int cur = 0, pre = 1;

bool Check(int mask)
{
    REP(i, n - 1) if (BIT(i, mask) && BIT(i + 1, mask)) return false;
    return true;
}

bool CheckPair(int mask1, int mask2)
{
    if (mask1 & mask2) return false;
    if (mask1 & (mask2 << 1)) return false;
    if (mask1 & (mask2 >> 1)) return false;
    return true;
}

void Reset(int &id)
{
    FOR(cnt, 0, 256) 
    {
        dp[id][cnt].assign(sz(v), vector<int>());
        REP(i, sz(v)) dp[id][cnt][i].assign(sz(valid[v[i]]), 0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> m >> n >> k;

    if (n > m) swap(m, n);
    REP(mask1, MK(n)) if (Check(mask1)) 
    {
        v.push_back(mask1);
        REP(mask2, MK(n)) if (CheckPair(mask1, mask2)) valid[mask1].push_back(mask2);
    }

    Reset(pre);    
    Reset(cur);

    REP(i, m) 
    {
        swap(cur, pre);
        Reset(cur);

        FOR(cnt, 0, k) REP(j, sz(v)) 
        {
            int mask1 = v[j];
            for (auto mask2 : valid[mask1]) 
        }
    }

    return 0;
}