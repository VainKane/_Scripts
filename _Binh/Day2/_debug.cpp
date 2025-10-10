#include <bits/stdc++.h>

using namespace std;

#define name "A"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int m = Rand(1e3, 1e3);
    int n = Rand(100, 100);
    int h = Rand(m / 8, m / 2);
    int w = Rand(n / 4, n / 2);

    cout << m << ' ' << n << '\n';
    cout << h << ' ' << w << '\n';

    while (m--) cout << Rand(0, 1);
    cout << '\n';
    while (n--) cout << Rand(0, 1);
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