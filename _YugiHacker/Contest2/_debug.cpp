#include <bits/stdc++.h>

using namespace std;

#define name "A"
#define ioname "lock"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(ioname".inp");

    int n = Rand(1, 1e6);
    int t = Rand(1, 1e5);

    cout << n << ' ' << t << '\n';
    while (t--)
    {
        int l = Rand(1, n);
        cout << l << ' ' << Rand(l, n) << '\n';
    }
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        // system(name".exe <"name".inp> "name".out");
        // system(name"_trau.exe <"name".inp> "name".ans");
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