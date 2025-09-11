#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "COUNTPL"

int const N = 1009;

int n;
string s;

int f[N][N];
int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> s;
    n = s.size();
    s = " " + s;

    FOR(i, 1, n) f[i][i] = f[i - 1][i] = true;

    cin >> s;
    FOR(i, 1, n) FOR(j, 1, n)
        f[i][j] = f[i][j] & (s[i] == s[j]);

    cout << f[1][3];

    return 0;
}