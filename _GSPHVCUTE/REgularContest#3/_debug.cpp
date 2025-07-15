#include <bits/stdc++.h>

using namespace std;

#define name "traffic"
#define file "I"

int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int t = Rand(1, 4);
    cout << t << '\n';

    while (t--)
    {
        int n = Rand(2, 1e2);
        cout << '\n' << n << '\n';
        for (int i = 2; i <= n; i++) 
        {
            int type = Rand(0, 2);
            int u = i;
            int v = Rand(1, i - 1);

            if (type) swap(u, v);
            cout << u << ' ' << v << '\n';
        }
    }
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(file".exe");
        system(file"_trau.exe");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}