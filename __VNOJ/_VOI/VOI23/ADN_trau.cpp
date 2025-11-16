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
string s, t = "ATGX";
char x[N];

int res = oo;

int Cal()
{
    int res = 0;

    FOR(i, 1, n) 
    {
        set<char> st;
        FOR(j, i, n)
        {
            st.insert(x[j]);
            res += sz(st) > 1;
        }
    }

    return res;
}

void Try(int pos)
{
    if (pos > n)
    {
        mini(res, Cal());
        return;
    }

    if (s[pos] != '?')
    {
        x[pos] = s[pos];
        Try(pos + 1);
        return;
    }

    REP(i, 4)
    {
        x[pos] = t[i];
        Try(pos + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> s;

    n = sz(s);
    s = " " + s;

    Try(1);
    cout << res;

    return 0;
}