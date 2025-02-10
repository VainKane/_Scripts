#include <bits/stdc++.h>

using namespace std;

int Sum(int n)
{
    int sum = 0;

    while (n)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int Solve(int n)
{
    int mi = 0;
    int res = INT_MAX;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int s = Sum(i);

            if (s > mi)
            {
                mi = s;
                res = i;
            }
            else if (s == mi) res = min(res, i);

            int j = n / i;
            s = Sum(j);

            if (s > mi)
            {
                mi = s;
                res = j;
            }
            else if (s == mi) res = min(res, j);

            cout << i << ' ' << j << '\n';
        }
    }

    return res;
}

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    cout << Solve(n);

    return 0;
}