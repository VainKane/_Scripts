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

int const N = 1e6 + 5;

int n, k;
long long c;

string ToString(__int128 x)
{
    string digits = "";
    while (x)
    {
        digits += x % 10 + '0';
        x /= 10;
    }

    reverse(all(digits));
    return digits;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> c;

    long long pre = 0, x;
    __int128 res = 0;

    FOR(i, 1, n)
    {
        res += pre + c;

        cin >> x;
        pre += x;

        assert(res > 0);
    }

    cout << ToString((res + c) * (n - 1));

    return 0;
}