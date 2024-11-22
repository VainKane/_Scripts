#include <bits/stdc++.h>

#define N 100001

int a[N];

int n;
int first;
int last;

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            std::cout << a[i] << '\n';
            break;
        }
    }

    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] % 2 == 0)
        {
            std::cout << a[i];
            break;
        }
    }
}