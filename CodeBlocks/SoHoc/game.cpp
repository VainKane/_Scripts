#include <bits/stdc++.h>

long long LuyThua(int x, int soMu);


int times;

int n;

long long x;
long long y;


int main()
{
    freopen("game.inp", "r", stdin);
    freopen("game.out", "w", stdout);

    std::cin >> times;

    for (int i = 0; i < times; i++)
    {
        std::cin >> x >> y >> n;

        if (n % 2 == 0)
        {
            x = x * std::pow(2, n / 2);
            y = y * std::pow(2, n / 2);
        }
        else
        {
            x = x * std::pow(2, n / 2 + 1);
            y = y * std::pow(2, n / 2);
        }

        std::cout << std::max(x, y) / std::min(x, y) << '\n';
    }

 
}

