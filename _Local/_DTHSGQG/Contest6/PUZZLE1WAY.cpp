#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 3009;

int n;
int a[N];

int f[N], s[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> a[i];

        // memset(f, 0, 4 * (n + 1));
        // memset(s, 0, 4 * (n + 1));
        
        memset(f, 0, sizeof f);

        f[1] = 1;
        FOR(i, 1, n) s[i] = 1;

        FOR(i, 1, n) FOR(j, 1, a[i])
        {
            if (i + j > n) break;
            maxi(f[i + j], f[i] + 1);
            s[i + j] += s[i];
        }

        cout << s[n] << ' ' << f[n] << '\n';
    }

    return 0;
}