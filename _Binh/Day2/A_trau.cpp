#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const M = 1e5 + 5;
int const N = 1e2 + 5;

int m, n;
int h, w;

string r, c;
int pre[M][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    cin >> h >> w;
    cin >> r >> c;

    int res = 0;

    #define GetSum(top, bot, left, right) pre[bot][right] - pre[top - 1][right] - pre[bot][left - 1] + pre[top - 1][left - 1]

    FOR(i, 1, m) FOR(j, 1, n)
    {
        int x = r[i - 1] == c[j - 1];
        pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + x;

        if (i >= h && j >= w) maxi(res, GetSum(i - h + 1, i, j - w + 1, j));
    }

    cout << res;

    return 0;
}