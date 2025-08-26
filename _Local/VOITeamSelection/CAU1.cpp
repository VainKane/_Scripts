#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "CAU1"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    int x, y;
    cin >> x >> y;

    long long res = 0;
    // FOR(m, 1, y) res += x / (m + 1) - x / (m * (m + 1));

    FOR(n, 1, x) FOR(m, 1, y) 
    {
        int tmp = n / m;
        res += (n % m) == tmp;
    }

    cout << res;

    return 0;
}