#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;

int n, k, d;
pair<int, int> a[N];
long long pre[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> d;
    FOR(i, 1, n) cin >> a[i].S >> a[i].F;

    sort(a + 1, a + n + 1);
    FOR(i, 1, n) pre[i] = pre[i - 1] + a[i].S;

    return 0;
}