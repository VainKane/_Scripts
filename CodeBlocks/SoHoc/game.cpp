#include <bits/stdc++.h>

int Play(int &x, int &y, int &n);

int times;

int n;

int x;
int y;


int main()
{
    freopen("game.inp", "r", stdin);
    freopen("game.out", "w", stdout);

    std::cin >> times;;

    for (int i = 0; i < times; i++)
    {
        std::cin >> x >> y >> n;
        std::cout << Play(x, y, n) << '\n';
    }

}

int Play(int &x, int &y, int &n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            x *= 2;
        }
        else
        {
            y *= 2;
        }
    }

    return std::max(x, y) / std::min(x, y);
}