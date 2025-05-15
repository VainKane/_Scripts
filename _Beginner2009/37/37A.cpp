#include <bits/stdc++.h>

using namespace std;

long long n;
int k;
int m = 0;

int prime[9] = {0, 2, 3, 5, 7, 11, 13, 17, 19};

long long res = 0;

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

long long Cal(int mask)
{
    int res = 1;
    for (int i = 0; i < m; i++)
    {
        if (bit(i, mask)) res *= prime[i + 1];
    }
    return n / res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= 8; i++) if (prime[i] <= k) m++;

    for (int mask = 1; mask < (1 << m); mask++)
    {
        int k = __builtin_popcount(mask);
        if (k & 1) res += Cal(mask);
        else res -= Cal(mask);
    }

    cout << n - res;

    return 0;
}