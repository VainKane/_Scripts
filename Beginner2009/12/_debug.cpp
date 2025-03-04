#include <bits/stdc++.h>

using namespace std;

#define name "12B"
int const ntest = 100;

mt19937_64 rd(time(0));
long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int f = Rand(2, 10);
    int v = Rand(f, 10);

    cout << f << ' ' << v << '\n';

    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            int a = Rand(-50, 50);
            cout << a << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    for (int itest = 1; itest <= ntest; itest++)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");

        if (system("fc "name".inp "name".ans") != 0)
        {
            cout << "Test " << itest << " WRONG!\n";
            return 0;
        }
        cout << "Test " << itest << " CORRECT!\n";
    }
}