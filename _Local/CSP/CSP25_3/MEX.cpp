#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int m, n;
vector<vector<int>> a;

int mid;

bool DFS(int x, int y)
{
    if (a[x + 1][y] != mid)
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> m >> n;

        a.resize(m + 5, vector<int> (n + 5));
        FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

        int l = 0;
        int r = m * n - 1;
        int res = 0;

        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (Check(mid))
            {
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
    }    

    return 0;
}