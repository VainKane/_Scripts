#include <bits/stdc++.h>

using namespace std;

#define name "102512A"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int oo = 1e5;
    int n = Rand(1, oo);
    int m = Rand(n - 1, oo);
    int q = Rand(1, oo);

    cout << n << ' ' << m << '\n';

    for (int i = 2; i <= n; i++)
    {
        cout << i << ' ' << Rand(1, i - 1) << '\n';
    }

    for (int i = 1; i <= m - n + 1; i++)
    {
        cout << Rand(1, n) << ' ' << Rand(1, n) << '\n';
    }

    cout << q << '\n';
    while (q--) cout << Rand(1, n) << ' ' << Rand(1, n) << '\n';
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(name".exe <"name".inp> "name".out");
        system(name"_trau.exe <"name".inp> "name".ans");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }

        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}