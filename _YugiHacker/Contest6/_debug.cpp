#include <bits/stdc++.h>

using namespace std;

#define name "A"
#define ioname "METRO"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(ioname".inp");

    int n = Rand(1, 1000);
    int oo = 1e9;

    cout << n << '\n';

    for (int i = 1; i <= n; i++) cout << Rand(1, oo) << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++)
    {
        int l = 1;
        int r = Rand(l, n);

        cout << l << ' ' << r << '\n';
    }
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");

        if (system("fc "ioname".out "ioname".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }

        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}