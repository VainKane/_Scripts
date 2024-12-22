#include <bits/stdc++.h>

using namespace std;

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b % 2 == 1)
        {
            res *= (a % 10);
            res %= 10;
        }

        b /= 2;
        a *= (a % 10);
    }

    return res;
}

int a;
int b;

int main()
{
    cin >> a >> b;

    cout << PowMod(a, b);
}