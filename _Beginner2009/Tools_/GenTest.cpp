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

    int n = Rand(1, 2e5);
    int q = Rand(1, 2e5);
    
    cout << n << ' ' << q << '\n';
    for (int i = 1; i <= n; i++) cout << Rand(1, 1e9) << ' ';
    while (q--) 
    {
        int l = Rand(1, n);
        cout << l << ' ' << Rand(l, n) << '\n';
    }
    
    return 0;
}