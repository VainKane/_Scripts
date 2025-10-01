#include <bits/stdc++.h>

using namespace std;

int Solve(int m, int k, int a1, int ak)
{
    long long s = a1 + 1LL * ak * k;

    if (m - s >= k || s == 0)
    {
        return (m - s) / k + (m - s) % k;
    }
    else
    {
        if (a1 + ak > 0)
        {
            for (int i = 0; i <= ak; i++)
            {
                if (m - k * i <= a1 && m - k * i >= 0) return 0;
            }
        }

        if (s < m) return 1;
        else 
        {
            if (m / k <= ak) return min(m % k, m - a1);
            return (long long)(m - a1 / k) * k + (m - a1 % k);
        }
    }
}

int t;

int m;
int k;
int a1;
int ak;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> m >> k >> a1 >> ak;
        cout << Solve(m, k, a1, ak) << '\n';
    }

    return 0;
}