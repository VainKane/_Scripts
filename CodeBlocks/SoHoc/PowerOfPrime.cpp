#include <bits/stdc++.h>

int Cal(int n, int p);


int times;
int n;
int p;

int main()
{
    // freopen("PowerOfPrime.inp", "w", stdin);
    // freopen("PowerOfPrime.out", "r", stout);

    std::cin >> times;
    
    for (int i = 0; i < times; i++)
    {
        std::cin >> n >> p;

        std::cout << Cal(n, p) << '\n';
    }
}

int Cal(int n, int p)
{
    int soMu = 0;
    int count = 0;

    for (int i = p; i <= n; i += p)
    {
        count += 1;
        // soMu += count;
    }

    return count;
}