#include <bits/stdc++.h>

using namespace std;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

int main()
{
    ofstream cout("testcase.inp");

    int n = Rand(1e5, 1e5);
    int m = Rand(1e5, n);
    int s = Rand(1, n);
    int t = Rand(1, n);

    cout << n << ' ' << m << ' ' << s << ' ' << t << '\n';
    while (m--)
    {
        int u = Rand(1, n);
        int v = Rand(1, n);
        int w = Rand(1, 1e9);

        cout << u << ' ' << v << ' ' << w << '\n';
    }

    return 0;
}