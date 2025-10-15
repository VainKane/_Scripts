#include <bits/stdc++.h>

using namespace std;

#define name "B"
int const ntest = 1;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int oo = 1000;

    int n = Rand(1, oo);
    cout << n << '\n';
    while (n--) cout << Rand(1, oo) << ' ';
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(name")
    }
}