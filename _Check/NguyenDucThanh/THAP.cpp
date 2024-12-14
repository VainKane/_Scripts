#include <bits/stdc++.h>

using namespace std;

void Tower(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << a << "->" << c << '\n';
    }
    else
    {
        Tower(n - 1, a, c, b);
        cout << a << "->" << c << '\n';
        Tower(n - 1, b, a, c);
    }
}

int n;

int main()
{
    cin >> n;
    Tower(n, 'A', 'B', 'C');
}