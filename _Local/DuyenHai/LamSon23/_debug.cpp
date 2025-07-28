#include <bits/stdc++.h>

using namespace std;

#define name "23on2b3"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int x = Rand(3, 1e5);
    int q = Rand(1, 1e2);
    cout << q << '\n';
    while (q--)
    {
        int l = Rand(1, x);
        cout << Rand(1, x) << ' ' << l << ' ' << Rand(l, x) << '\n';
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