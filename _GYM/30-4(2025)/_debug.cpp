#include <bits/stdc++.h>

using namespace std;

#define name "C"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(2, 10);
    int m = Rand(n - 1, 15);
    int q = Rand(1, 4);

    int a[n + 1];
    for (int i = 1; i <= n; i++) a[i] = i;
    random_shuffle(a + 1, a + n + 1);

    cout << n << ' ' << m << ' ' << q << '\n';

    for (int i = 1; i <= n; i++)
    {
        int type = Rand(1, 10);
        
        int s, c;
        if (type == 0) cout << "0 0\n";
        else cout << Rand(1, 3) <<  ' ' << Rand(1, 5) << '\n';
    }

    for (int i = 2; i <= n; i++)
    {
        cout << a[i] << ' ' << a[Rand(1, i - 1)] << ' ' << Rand(1, 10) << '\n';
    }
    for (int i = 1; i <= m - n + 1; i++) cout << Rand(1, n) << ' ' << Rand(1, n) << ' ' << Rand(1, 10) << '\n';

    for (int i = 1; i <= q; i++)
    {
        int l = Rand(1, 3);
        int h = Rand(l, 10);

        cout << l << ' ' << h << ' ' << Rand(1, 1e14) << '\n';
    }
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
}