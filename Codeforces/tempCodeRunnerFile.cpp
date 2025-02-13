#include <bits/stdc++.h>

using namespace std;

int const mod = 10000;

int PowMod(int a)
{
    return (1LL * (a % mod) * (a % mod)) % mod;
}

int a;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> n;

    int pre = a;

    for (int i = 1; i < n; i++)
    {
        a = PowMod(pre);
        pre = a;
    }

    cout << pre;

    return 0;
}