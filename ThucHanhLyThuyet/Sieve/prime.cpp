#include <bits/stdc++.h>

using namespace std;

bool p[(int)1e6 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(p, 1, sizeof p);
    p[0] = p[1] = false;

    for (int i = 2; i <= sqrt(1e6); i++)
    {
        if (p[i])
        {
            for (int j = i * i; j <= 1e6; j += i)
            {
                p[j] = false;
            }    
        }
    }

    int n;
    while (cin >> n)
    {
        if (p[n]) cout << n << " is prime!\n";
        else cout << n << " is not prime!\n";
    }

    return 0;
}