#include <bits/stdc++.h>

using namespace std;

#define name "trochoi"

int const N = 1e6 + 5;

int n;

int a[N];
int prime[N];

long long Cal(int x)
{
    long long res = 1;

    while (true)
    {
        int k = prime[x];
        int p = 1;

        if (x == 1) break;

        while (x % k == 0)
        {
            p *= k;
            x /= k;
        }

        res *= (1ll * (p * k - 1) / (k - 1));
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;

    for (int i = 2; i <= 1000; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= 1e6; j += i)
            {
                prime[j] = i;
            }
            prime[i] = i;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cout << Cal(x) << ' ';
    }

    return 0;
}
