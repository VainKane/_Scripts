#include <bits/stdc++.h>

using namespace std;

int Solve(long long x, int y, int k)
{
    long long s = ((x / y) + 1) * y;

    while (x + k >= s)
    {
        x = s / y;
        k -= (s - x);

        s = ((x / y) + 1) * y;
    }

    return x + k;
}

int t;

long long x;
int y;
int k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> x >> y >> k;
        cout << Solve(x, y, k) << '\n';
    }

    return 0;
}