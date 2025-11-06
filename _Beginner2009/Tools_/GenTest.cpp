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

    // int n = 1e5;
    // for (int i = 1; i <= n; i++) cout << (char)Rand('a', 'a');
    // cout << ' ';
    // while (n--) cout << (char)Rand('a', 'a');

    cout << "1\n";
    int n = Rand(1, 2e5);
    int m = Rand(1, 2e5);

    cout << n << ' ' << m << '\n';
    for (int i = 1; i <= m; i++)
    {
        int a = Rand(1, n);
        int d = Rand(1, 10);
        int k = Rand(0, (n - a) / d);

        cout << a << ' ' << d << ' ' << k << '\n';
    }
    
    return 0;
}