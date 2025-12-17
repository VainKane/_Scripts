#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

#define name "fc082_treecolor"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int lim = 1e5;
    int oo = 1e9;
    int n = Rand(1, lim);

    int a[n + 1];
    FOR(i, 1, n) a[i] = i;
    random_shuffle(a + 1, a + n + 1);

    cout << n << '\n';
    FOR(i, 2, n) cout << a[i] << ' ' << a[Rand(1, i - 1)] << '\n';
    FOR(i, 1, n) cout << Rand(1, oo) << ' ';
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