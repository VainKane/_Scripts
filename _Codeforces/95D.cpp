#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

int const N = 1e3 + 4;
int const MOD = 1e9 + 7;

int t, k;
string l, r;

int dp[N][2][N][3];

void Add(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int Get(string x)
{
    memset(dp, 0, sizeof dp);
    dp[0][0][0][0] = 1;

    int n = x.size();

    REP(i, n) FOR(r, 0, 1) REP(last, n) FOR(cnt, 0, 2) if (dp[i][r][last][cnt])
    {
        int lim = (r ? 9 : x[i] - '0');
        FOR(d, 0, lim) 
        {
            int newLast = last;
            int newCnt = cnt;

            if (d == 4 || d == 7)
            {
                newCnt = min(2, cnt + (i - last <= k || i == 0));
                newLast = i;
            }

            Add(dp[i + 1][r | (d < lim)][newLast][newCnt], dp[i][r][last][cnt]);
        }
    }

    int res = 0;
    FOR(r, 0, 1) FOR(last, 0, n) Add(res, dp[n][r][last][2]);

    return res;
}

bool Check(string x)
{
    int last = -1e9;
    REP(i, x.size())
    {
        if (x[i] == '4' || x[i] == '7')
        {
            if (i - last <= k) return true;
            last = i;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t >> k;
    while (t--)
    {
        cin >> l >> r;
        cout << Get(r) - Get(l) + Check(l) << '\n';
    }

    return 0;
}