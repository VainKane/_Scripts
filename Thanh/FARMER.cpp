#include <bits/stdc++.h>

using namespace std;

int const mod = 1e9 + 7;

int n;
int q;

int a[(int)1e6 + 10];   

int l;
int r;

long long p[(int)1e6 + 10];
int s[(int)1e6 + 10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;

    cin >> a[1];
    p[1] = a[1];
    
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        long long x = a[i];
        x *= (p[n] - p[i]) % mod;
        x %= mod;
        s[i] = x;
    }

    // for (int i = 1; i <= n; i++) cout << s[i] << ' ';
    // cout << '\n';

    while (q--)
    {
        cin >> l >> r;
        long long res = 0;
        for (int i = l; i <= r; i++)
        {
            res += (a[i] * ((p[r] - p[i]) % mod)) % mod;
        }

        cout << res << '\n';
    }

    return 0;
}