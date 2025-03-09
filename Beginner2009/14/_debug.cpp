#include <bits/stdc++.h>

using namespace std;

#define name "14D"
int const ntest = 1e6;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, (int)3e5);
    cout << n << '\n';
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int type = 1;
        if (i != 1) type = Rand(1, 2);
        int x = Rand(1, (int)1e9);
        if (type == 2) x = Rand(1, cnt);
        else cnt++;

        cout << type << ' ' << x << '\n';
    }
}

int main()
{
    for (int itest = 1; itest <= ntest; itest++)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");
        
        if (system("fc "name".ans "name".out") != 0)
        {
            cout << "Test " << itest << " WRONG!\n";
            return 0;
        }
        cout << "Test " << itest << " CORRECT!\n";
    }
}