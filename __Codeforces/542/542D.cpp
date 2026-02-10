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

long long GCD(long long a, long long b)
{
    while (true)
    {
        if (a == 0 || b == 0 || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }
}

long long F(long long &x)
{
    long long res = 0;
    for (long long i = 1; i <= sqrt(x); i++) if (x % i == 0)
    {
        if (GCD(i, x / i) == 1) res += i + x / i;
    }
    return res;
}

map<long long, int> cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int ma = 0;
    for (long long i = 1; i <= 1e7; i++) maxi(ma, ++cnt[F(i)]);
    cout << ma;

    return 0;
}