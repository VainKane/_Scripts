#include <bits/stdc++.h>

#define max(a, b) ((a > b) ? a : b)

using namespace std;

int a[59];
int b[59];
int c[59];

void Sum(int n, long long &res, char type, int cnt)
{
    if (n == 1)
        return;

    if (type == 'b')
        for (int i = 0; i < n; i++)
            a[i] = b[i];
    else
        for (int i = 0; i < n; i++)
            a[i] = c[i];

    long long s = 0;

    for (int i = 1; i < n; i++)
    {
        b[i] = a[i] - a[i - 1];
        s += 1LL * b[i];

        res = max(res, s);

        Sum(n - 1, res, 'b', cnt);
        Sum(n - 1, res, 'c', cnt);
    }

    s = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        c[i] = a[i] - a[i + 1];
        s += 1LL * c[i];

        res = max(res, s);

        Sum(n - 1, res, 'c', cnt);
        Sum(n - 1, res, 'b', cnt);
    }
}

int t;
int n;

long long res;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = c[i] = a[i];
        }

        if (n > 1)
        {
            Sum(n, res, 'b', 0);
            cout << res << '\n';
        }
        else
            cout << a[0] << '\n';
    }

    return 0;
}