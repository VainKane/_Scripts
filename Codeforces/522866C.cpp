#include <bits/stdc++.h>

using namespace std;

int Sum(int a, int b)
{
    return -a * a + a + b * b + b;
}

int n;

int a = 0;
int b = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    b = sqrt(n);

    while (a <= b)
    {
        int s = Sum(a,b);

        if (s < 2 * n)
        {
            if (a >= 1)
            {
                if (Sum(a - 1, b))
            }
        } 
        else a++;
    }

    cout << a << ' ' << b;

    return 0;
}