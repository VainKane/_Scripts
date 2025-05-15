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

    int n = 10;

    cout << n << '\n';
    for (int i = 1; i <= n; i++)
    {
        
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