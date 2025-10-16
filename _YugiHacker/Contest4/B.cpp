#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "minprod"

int const N = 1e5 + 5;

int n;
int a[N], b[N];

double p1[N], p2[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    FOR(i, 1, n) 
    {
        p1[i] = 1.0 * a[i] / b[i];
        p2[i] = 1.0 * b[i] / a[i];
    }

    sort(p1 + 1, p1 + n + 1);
    sort(p2 + 1, p2 + n + 1);

    

    return 0;
}