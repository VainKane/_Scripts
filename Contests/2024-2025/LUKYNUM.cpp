#include <bits/stdc++.h>

using namespace std;

bool Check(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int Sum(int n)
{
    int res = 0;

    while (n)
    {
        res += n % 10;
        n /= 10;
    }

    return res;
}

int t;
int l;
int r;

bool prime[50];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 49; i++)
    {
        prime[i] = Check(i);
    }

    cin >> t;

    while (t--)
    {
        cin >> l >> r;
        int cnt = 0;

        for (int i = l; i <= r; i++)
        {
            if (prime[Sum(i)])
            {
                cnt++;
            }
        }

        cout << cnt << '\n';
    }
}