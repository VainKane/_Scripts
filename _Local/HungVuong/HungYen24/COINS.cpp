#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "COINS"

int k, l, m;
int n;

char Solve()
{
    FOR(x, 0, n / k)
    {
        int z = n - k * x;
        if (z % l == 0)
        {
            int y = z / l;
            if ((x + y) & 1) return 'A';
        }
    }

    return 'B';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> k >> l >> m;
    FOR(i, 1, m)
    {
        cin >> n;
        cout << Solve();
        
    }

    return 0;
}