#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 3e5 + 5;

int n;
int x[N], y[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".ans", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> x[i] >> y[i];

    int q; cin >> q;
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int res = 0;
        FOR(i, 1, n) 
        {
            if ((x[i] == x1 || x[i] == x2) && y[i] >= y1 && y[i] <= y2) res++;
            else res += (y[i] == y1 || y[i] == y2) && x[i] >= x1 && x[i] <= x2;
        }
        cout << res << '\n';
    }

    return 0;
}