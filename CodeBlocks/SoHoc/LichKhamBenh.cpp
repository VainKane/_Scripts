#include <bits/stdc++.h>

int times;
int n;
int x;

int main()
{
    std::cin >> times;

    for (int i = 0; i < times; i++)
    {
        std::cin >> n >> x;
        std::cout << 10 * (n - 1) - (n - 1) * x << '\n'; 
    }
}
