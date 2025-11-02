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

    int n = Rand(1, 1e5);
    cout << n << '\n';
    while (n--) cout << "2 ";
    
    return 0;
}