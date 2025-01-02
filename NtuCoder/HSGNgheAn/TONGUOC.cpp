#include <bits/stdc++.h>

using namespace std;

long long a;
long long b;

long long sum = 0;

int main()
{
    cin >> a >> b;

    for (int i = 1; i <= sqrt(a); i++)
    {
        if (a % i == 0 && b % (3 * i) == 0)
        {
            sum += i;
        }
    }

    cout << sum;

    return 0;
}