#include <bits/stdc++.h>

void Round(int &n);

int n;

int main()
{
    // freopen("Rounding.inp", "r", stdin);
    // freopen("Roudning.out", "w", stdout);

    std::cin >> n;
    
    Round(n);

    std::cout << n;
}

void Round(int &n)
{
    if (n % 10 < 5)
    {
        n /= 10;
        n *= 10;
    }
    else
    {
        n /= 10;

        int temp = n % 10;

        n /= 10;
        n *= 10;
        n += temp + 1;
        
        n *= 10; 
    }
}