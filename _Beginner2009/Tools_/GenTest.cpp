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

    int n = Rand(8, 10);
    int m = n - 1;
    
    cout << n << ' ' << m << '\n';
    for (int i = 2; i <= n; i++)
    {
        cout << i << ' ' << Rand(1, i - 1) << ' ' << Rand(0, 1e9) << '\n';
    }

    for (int i = 1; i <= m - n + 1; i++) 
    {
        int u = Rand(1, n - 1);
        cout << u << ' ' << Rand(u + 1, n) << Rand(0, 1e9) << '\n';
    }
    
    return 0;
}