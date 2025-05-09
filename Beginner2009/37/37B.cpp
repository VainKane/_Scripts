#include <bits/stdc++.h>

using namespace std;

int const N = 25;

int n;
long long k;

int a[N];

long long res1 = 0;
long long res2 = 0;

int m = 0;

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

long long GCD(long long a, long long b)
{
    long long r = a % b;
    if (!r) return b;

    while (r)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

long long Cal(int mask)
{
    long long res = 1;
    for (int i = 0; i < m; i++)
    {
        if (bit(i, mask)) 
        {
            long long gcd = GCD(res, a[i + 1]);
            if (res / gcd > k / a[i + 1]) return 0;
            res *= (a[i + 1] / gcd);
        }
    }
    return k / res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
    {
        int x; cin >> x;
        if (x <= k) a[++m] = x;
    }

    for (int mask = 1; mask < (1 << m); mask++)
    {
        int k = __builtin_popcount(mask); 
        long long x = Cal(mask);

        if (k & 1) 
        {
            res1 += x;
            res2 += k * x;
        }
        else 
        {
            res1 -= x;
            res2 -= k * x;
        }
    }

    cout << res1 << ' ' << res2;

    return 0;
}