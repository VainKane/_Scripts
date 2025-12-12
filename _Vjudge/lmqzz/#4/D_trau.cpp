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

int const N = 509;

int n;
int a[N];

bool dp[2][N * N];
int sum = 0;

bool CheckSum(int s, int banned)
{
    if (s & 1) return false;

    int cur = 1, pre = 0;
    REP(state, 2) memset(dp[state], false, (s + 1));
    dp[pre][0] = 1;

    FOR(i, 1, n + 1) if (i != banned)
    {
        FOR(j, 0, s / 2)
        {
            dp[cur][j] = dp[pre][j];
            if (j - a[i] >= 0) dp[cur][j] |= dp[pre][j - a[i]];
        }

        if (dp[cur][s / 2]) return true;

        swap(cur, pre);
        memset(dp[cur], false, (s + 1));
    }

    return false;
}

bool Check()
{
    FOR(i, 1, n + 1) if (!CheckSum(sum - a[i], i)) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], sum += a[i];

    vector<int> res;
    FOR(x, 1, 2 * sum) 
    {
        a[n + 1] = x;
        sum++;

        if (Check()) res.push_back(x);
    }

    cout << sz(res) << '\n';
    for (auto &x : res) cout << x << ' ';

    return 0;
}