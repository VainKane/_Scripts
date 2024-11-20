#include <bits/stdc++.h>

std::string Solve(int n, int a, int b, int &xOut, int &yOut);


int n;

int a;
int b;

int x; 
int y;

int main()
{
    freopen("Buy.inp", "r", stdin);
    freopen("Buy.out", "w", stdout);

    std::cin >> n >> a >> b;

    std::cout << Solve(n, a, b, x, y) << '\n';
    
    if (Solve(n, a, b, x, y) == "YES")
    {
        std::cout << x << ' ' << y;
    }
}

std::string Solve(int n, int a, int b, int &xOut, int &yOut)
{
    for (int y = 0; y <= n; y++)
    {
        if ((n - y * b) % a == 0)
        {
            yOut = y;
            xOut = (n - y * b) / a;

            return "YES";
        }
    }

    return "NO";
}