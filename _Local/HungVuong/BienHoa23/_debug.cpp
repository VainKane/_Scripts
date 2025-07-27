#include <bits/stdc++.h>

using namespace std;

#define name "XORGAND"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, 2e5);
    int q = Rand(1, 1e3);

    cout << n << '\n';
    for (int i = 1; i <= n; i++) cout << Rand(1, 1e9) << ' ';
    cout << q << '\n';
    for (int i = 1; i <= n; i++)
    {
        int l = Rand(1, n);
        cout << l << ' ' << Rand(l, n) << ' ' << Rand(1, 1e9) << '\n';
    }
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }

        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}