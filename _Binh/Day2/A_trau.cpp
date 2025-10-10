#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const M = 1e5 + 5;
int const N = 1e2 + 5;

int m, n;

char r[M], c[N];
int a, b;

int Count(int top, int bot, int left, int right)
{
    int res = 0;

    FOR(i, top, bot) FOR(j, left, right)
    {
        if (r[i] == '1' && c[j] == '1') res++;
        else if (r[i] == '0' && c[j] == '0') res++;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("A.inp", "r", stdin);

    cin >> m >> n;
    cin >> a >> b;
    FOR(i, 1, m) cin >> r[i];
    FOR(i, 1, n) cin >> c[i];

    int res = 0;
    FOR(i, 1, m - a + 1) FOR(j, 1, n - b + 1)
    {
        res = max(res, Count(i, i + a - 1, j, j + b - 1));
    }
    cout << res;

    return 0;
}