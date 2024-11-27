#include <bits/stdc++.h>

long double nums[101];

long double average = 0;
long double value = 0;

int n;

int main()
{
    std::cout << std::fixed << std::setprecision(2);
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
        average += nums[i] / n;
    }

    value = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (abs(average - value) > abs(average - nums[i]))
        {
            value = nums[i];
        }
    }

    std::cout << average << '\n' << value;
}