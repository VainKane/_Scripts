#include <bits/stdc++.h>

using namespace std;

#define file "7"
#define name "query"

int const ntest = 10;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(3e5, 3e5);
    int q = Rand(3e5, 3e5);

    cout << 2 << '\n' << n << '\n';
    for (int i = 2; i <= n; i++) cout << Rand(1, i - 1) << ' ';

    cout << '\n' << q << '\n';
    for (int i = 1; i <= q; i++)
    {
        int type = Rand(1, 2);
        int u = Rand(1, 1);

        if (type == 1) cout << "get " << u << '\n';
        else cout << "pos " << u << ' ' << Rand(1, 15) << '\n';
    }
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(file".exe");
        system(file"_trau.exe");

        if (system("fc "name".ans "name".out") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}