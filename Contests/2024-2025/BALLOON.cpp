#include <bits/stdc++.h>

using namespace std;

int Min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int n;
int x;
int y;

int main()
{
    cin >> n >> x >> y;

    if (n < 5)
    {
        cout << n * x;
    }
    else
    {
        cout << n * Min(x, y);
    }

    return 0;
}