#include <bits/stdc++.h>

using namespace std;

#define name "snad"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int t = Rand(1, 20);
    cout << t << '\n';
    while (t--) 
    {
        long long l = Rand(1, 1e18);
        cout << l << ' ' << Rand(l, 1e18) << '\n';
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

    return 0;
}