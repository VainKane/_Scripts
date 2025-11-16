#include <bits/stdc++.h>

using namespace std;

#define name "ROBOT"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int w = Rand(1, 1);
    int l = Rand(1, 200);
    int n = Rand(1, 2);
    int q = Rand(1, 2);

    cout << w << ' ' << l << ' ' << n << ' ' << q << '\n';
    while (n--) cout << Rand(1, w) << ' ' << Rand(1, l) << '\n';
    while (q--) cout << Rand(1, w) << ' ' << Rand(1, l) << '\n';
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