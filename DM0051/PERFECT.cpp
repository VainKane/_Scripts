#include <bits/stdc++.h>

using namespace std;

long long pi(int n)
{
    long long sum = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += (long long)i;

            if (i * i != n)
            {
                sum += (long long)(n / i);
            }
        }
    }

    sum = abs(sum - 2 * (long long)n);

    return sum;
}

int a;
int b;

long long sum = 0;

int main()
{
    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        // cout << i << ' ' << pi(i) << '\n';
        sum += (long long)pi(i);
    }

    cout << sum;

    return 0;
}