#include <bits/stdc++.h>

using namespace std;

long long ToHop(int k, int n)
{
    if (k == n || k == 0)
    {
        return 1;
    }
    else
    {
        return ToHop(k - 1, n - 1) + ToHop(k, n - 1);
    }
}

int n;
int k;

int main()
{
    freopen("TOHOP.INP", "r", stdin);
    freopen("TOHOP.OUT", "w", stdout);

    std::cin >> n >> k;

    cout << ToHop(k, n) << endl;
    return 0;
}
