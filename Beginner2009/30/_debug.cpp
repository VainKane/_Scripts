#include <bits/stdc++.h>

using namespace std;

#define name "30B"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, 10);
    int m = Rand(1, 10);

    cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << i << ' ';
    }

    cout << '\n';
    
    for (int i = 1; i <= m; i++)
    {
        int type = Rand(1, 2);
        cout << type << ' ';
        if (type == 1)
        {
            int a = Rand(1, n);
            int b = Rand(1, n);

            cout << a << ' ' << b;
        }
        else
        {
            int l = Rand(1, n);
            int r = Rand(l, n);

            cout << l << ' ' << r;
        }

        cout << '\n';
    }
}

int main()
{
    for (int itest = 1; itest <= ntest; itest++)
    {
        GenTest();
        system("./"name);
        system("./"name"_trau");

        if (system("diff "name".out "name".ans") != 0)
        {
            cout << "Test: " << itest << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << itest << " CORRECT!\n";
    }
}