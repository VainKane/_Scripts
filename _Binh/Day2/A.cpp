#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;

int r, c;
int h, w;

int cntR[N][2];
int cntC[N][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> r >> c;
    cin >> h >> w;

    FOR(i, 1, r)
    {
        char ch; cin >> ch;
        REP(j, 2) cntR[i][j] = cntR[i - 1][j] + (ch == '0' + j);
    }
    FOR(i, 1, c)
    {
        char ch; cin >> ch;
        REP(j, 2) cntC[i][j] = cntC[i - 1][j] + (ch == '0' + j);
    }

    long long res = 0;


    cout << res;

    return 0;
}