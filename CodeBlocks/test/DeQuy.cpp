#include <bits/stdc++.h>

int GCD(int a, int b);
int Replace(int n);
int Reverse(int n);

int a;
int times;

int main()
{
    std::cin >> times;

    for (int i = 0; i < times; i++)
    {
        std::cin >> a;
        std::cout << Reverse(Replace(a)) << '\n';
    }
    
}

int Replace(int n)
{
    int result = 0;

    int r = n % 10;

    if (n == 0)
    {
        return 5;
    }

    while (n > 0)
    {
        r = n % 10;

        if (r == 0)
        {
            result += 5;
        }
        else
        {
            result += r;
        }

        result *= 10;
        n /= 10;

    }

    result /= 10;

    return result;
}

int Reverse(int n)
{
    int reversedNum = 0;

    while (n > 0)
    {
        reversedNum += n % 10;
        reversedNum *= 10;

        n /= 10;
    }

    reversedNum /= 10;

    return reversedNum;
}

int GCD(int a, int b)
{
    a = abs(a);
    b = abs(b);

    if (a == b)
    {
        return a;
    }
    else if (a * b == 0)
    {
        return a + b;
    }
    else
    {
        if (a > b)
        {
            GCD(b, a - b);
        }
        else
        {
            GCD(a, b - a);
            
        }
    }
}
