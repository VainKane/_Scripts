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

    int n = 5000;
    int m = 10000;

    cout << n << '\n';
    for (int i = 1; i <= n; i++)
    {
        int a = Rand(0, 1e4);
        int b = Rand(0, 1e4);

        cout << a << ' ' << b << '\n';
    }
    cout << m << '\n';

    while (m--)
    {
        int a = Rand(1, n);
        int b = Rand(1, n);

        while (b == a) b = Rand(1, n);
        cout << a << ' ' << b << '\n';
    }

    return 0;
}