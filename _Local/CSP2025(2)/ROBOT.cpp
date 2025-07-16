#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

int const N = 5009;

int n, m;
int a[N];
pair<int, int> b[N];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.F < b.F;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i].F >> b[i].S;

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1, cmp);

    FOR(i, 1, m) FOR(j, 1, n)
    {
        FOR(z, )
    }

    return 0;
}