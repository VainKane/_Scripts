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
#define name "ADN"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 109;
int const oo = 1e9;

int n;
string s;

int a[N][2];
char x[N];

int res = oo;

int Cal()
{
    int res = 0;

    int j = 1;
    FOR(i, 1, n) 
    {
        while (x[i] == x[j] && j < n) j++;
        if (x[i] != x[j]) res += n - j + 1;
    }

    return res;
}

void Try(int pos)
{
    if (pos > n)
    {
        mini(res, Cal());
        // FOR(i, 1, n) cout << x[i];
        // cout << '\n' << Cal() << '\n';
        return;
    }

    if (s[pos] != '?') 
    {
        x[pos] = s[pos];
        Try(pos + 1);
        return;
    }

    REP(i, 2)
    {
        x[pos] = a[pos][i];
        Try(pos + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> s;

    n = sz(s);
    s = "A" + s + "A";

    FOR(i, 1, n) if (s[i] == '?')
    {
        FORD(j, i - 1, 0) if (s[j] != '?')
        {
            a[i][0] = s[j];
            break;
        }

        FOR(j, i + 1, n + 1) if (s[j] != '?')
        {
            a[i][1] = s[j];
            break;
        }
    }

    Try(1);
    cout << res;

    return 0;
}