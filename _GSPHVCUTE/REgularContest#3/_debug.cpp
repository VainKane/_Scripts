#include <bits/stdc++.h>

using namespace std;

#define name "raspored"
#define file "F"

int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");
 
    int n = Rand(1, 8);
    int q = Rand(1, 8);

    int d[n + 1];

    cout << "2\n";
    cout << n << ' ' << q << '\n';
    for (int i = 1; i <= n; i++) 
    {
        d[i] = Rand(1, 1e2);
        cout << Rand(1, 1e3) << ' ' << d[i] << '\n';
    }
    for (int i = 1; i <= q; i++) 
    {
        int idx = Rand(1, n);
        cout << idx << ' ' << Rand(1, 1e3) << ' ' << d[idx] << '\n';
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