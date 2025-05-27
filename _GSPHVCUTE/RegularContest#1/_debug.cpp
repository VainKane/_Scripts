#include <bits/stdc++.h>

using namespace std;

#define name "password"
#define task "J"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, 25);
    int a[n + 2];

    a[1] = n;

    for (int i = 2; i <= n; i++)
    {
        a[i] = Rand(0, max(a[i - 1] - 1, 0));
    }

    cout << n << '\n';
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(task".exe");
        system(task"_trau.exe");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << i << " CORRECT!\n";
    }
}