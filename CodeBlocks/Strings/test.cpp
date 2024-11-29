#include <bits/stdc++.h>

int s1;
int s2;

int main()
{
    std::cin >> s1 >> s2;

    for (int i = 1; i <= s2 / 4; i++)
    {
        if (2 * (s1 - i) + 4 * i == s2)
        {
            std::cout << s1 - i << ' ' << i;
        }
    }
}