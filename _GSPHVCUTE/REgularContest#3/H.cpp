#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define F first
#define S second
#define name "robot"

int const N = 84;
int const K = 2001;
int const OS = 82;

int t;
int n, k;
string s;

bool dp[N][K][2][2 * N];

char Rev(char ch)
{
    if (ch == 'M') return 'D';
    return 'M';
}

void Solve()
{
    memset(dp, false, sizeof dp);

    dp[0][0][0][OS] = true;
    REP(i, n) FOR(o, 0, i) REP(d, 2) FOR(pos, -n, n) if (dp[i][o][d][pos + OS])
    {
        pos += OS;
        int newPos = pos + (d ? -1 : 1);

        if (s[i] == 'D')
        {   
            dp[i + 1][o][!d][pos] = true;
            if (o < k) dp[i + 1][o + 1][d][newPos] = true;
        }
        else
        {
            dp[i + 1][o][d][newPos] = true;
            if (o < k) dp[i + 1][o + 1][!d][pos] = true;
        }
    }

    int res = 0;

    for (int o = k & 1; o <= k; o += 2) 
    REP(d, 2) FOR(pos, -n, n) if (dp[n][o][d][pos + OS]) res = max(res, abs(pos));

    cout << res << '\n';

    if (k == 1) cout << dp[3][1][0][3 + OS];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        cin >> s;
        Solve();
    }

    return 0;
}