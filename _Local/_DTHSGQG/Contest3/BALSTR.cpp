#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(v) ((int)v.size())

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 109;

int n;
string s;
int dp[N][N][N];

int cnt[2][N];

void Init()
{
    n = sz(s);
    s = " " + s;

    FOR(i, 1, n) REP(j, 1)
        cnt[j][i] = cnt[j][i - 1] + s[i] == '0' + j;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    Init();

    memset(dp, 0x3f, sizeof dp);

    FOR(i, 1, n) FOR(cnt0, 0, cnt[0][n]) FOR(cnt1, 0, cnt[1][n]) 
    {
        if ((cnt0 & 1) && (cnt1 & 1)) continue;
        FOR(j, 1, i - 1) FOR(cnt00, 0, cnt0) FOR(cnt11, 0, cnt1)
        {
            mini(dp[i][cnt0][cnt1], dp[j][cnt00][cnt11] + );
        }
    }

    return 0;
}