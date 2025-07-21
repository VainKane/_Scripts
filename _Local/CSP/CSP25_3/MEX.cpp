#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define name "MEX"

int const N = 1009;

int t;
int m, n;

int a[N][N];
vector<int> b[N][N];

int Find(vector<int> v)
{
    sort(all(v));
    FOR(i, 1, v.size() - 1)
    {
        if (v[i] != v[i - 1] + 1) return v[i];
    }

    return v.back() + 1;
}

void Solve()
{
    FOR(i, 1, m) FOR(j, 1, n) b[i][j].clear();
    FOR(i, 1, m)
    {
        if (i > 2) FOR(j, 1, n) b[i - 2][j].clear();

        FOR(j, 1, n)
        {
            vector<int> v1 = b[i - 1][j];
            vector<int> v2 = b[i][j - 1];

            v1.push_back(a[i][j]);
            v2.push_back(a[i][j]);

            b[i][j] = ((Find(v1) > Find(v2)) ? v1 : v2);
        }
    }

    cout << Find(b[m][n]) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> t;
    while (t--)
    {
        cin >> m >> n;

        FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];
        Solve();
    }

    return 0;
}
