#include <bits/stdc++.h>

using namespace std;

int const mod = 1e9 + 7;

int f[(int)1e5 + 10];

int n;

int main()
{
    cin >> n;

    f[1] = 1;
    f[2] = 2;
    f[3] = 4;

    for (int i = 4; i <= n; i++)
    {
        f[i] = ( (long long)(f[i - 1] % mod) + f[i - 2] % mod + (long long)(f[i - 3] % mod) ) % mod;
    }


    cout << f[n];

    return 0;
}
