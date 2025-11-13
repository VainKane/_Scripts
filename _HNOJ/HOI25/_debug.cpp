#include <bits/stdc++.h>

using namespace std;

#define name "XOREX"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest1()
{
    ofstream cout(name".inp");

    int n = (1 << (Rand(0, 19)));
    int q = Rand(1, 1e3);
    int oo = 1e6;

    cout << n << ' ' << q << '\n';
    for (int i = 0; i < n; i++) cout << Rand(0, 10) << ' ';
    cout << '\n';

    while (q--)
    {
        int type = Rand(1, 3);
        cout << type << ' ';
        if (type == 1) cout << Rand(0, n - 1) << '\n';
        else
        {
            int l = Rand(0, n - 1);
            cout << l << ' ' << Rand(l, n - 1) << '\n';
        }
    }
}

void GenTest6()
{
    ofstream cout(name".inp");

    int n = (1 << (Rand(0, 19)));
    int q = Rand(1, 1e3);
    int oo = 1e6;

    cout << n << ' ' << q << '\n';
    for (int i = 0; i < n; i++) cout << Rand(0, oo) << ' ';
    cout << '\n';

    while (q--)
    {
        int type = Rand(1, 3);
        cout << type << ' ';
        if (type == 1) cout << Rand(0, n - 1);
        else cout << "0 " << n - 1;
        cout << '\n';
    }
}

void GenTest()
{
    
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest6();
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