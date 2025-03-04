#include <bits/stdc++.h>

using namespace std;

#define name "11G"
const int ntest = 10000;

mt19937_64 rd(time(0));
long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");
    int n = Rand(1, 10);

    cout << n << '\n';

    for (int i = 1; i <= n; i++)
    {
        int a = Rand(1, 6);
        int b = Rand(1, 6);

        cout << a << ' ' << b << '\n';
    }
}

int main()
{
    for (int itest = 1; itest <= ntest; itest++)
    {
        GenTest();
        system(name"_trau.exe");
        system(name".exe");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << itest << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << itest << " CORRECT!\n";
    }
}