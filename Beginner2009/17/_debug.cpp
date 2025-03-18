#include <bits/stdc++.h>

using namespace std;

#define name "17E"
int const ntest = 1e6;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(3, 1000);
    int m = Rand(3, 1000);
    int a = Rand(2, m);
    int b = Rand(2, n);
    cout << m << ' ' << n << '\n';

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int t = Rand('a', 'z');
            cout << (char)t;
        }
        cout << '\n';
    }
    cout << a << ' ' << b;
}

int main()
{
    for (int itest = 1; itest <= ntest; itest++)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << itest << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << itest << " CORRECT!\n";
    }
}