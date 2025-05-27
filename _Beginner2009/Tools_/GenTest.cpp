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

    for (int i = 1; i <= 1000; i++)
    {
        int type = Rand(1, 2);
        if (type == 1) cout << 'A';
        else cout << 'B';
    }

    return 0;
}