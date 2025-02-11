#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;
vector<vector<bool>> t;

int n;
int m;

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    a.resize(n + 9, vector<int> (m + 9));
    t.resize(n + 9, vector<bool> (m + 9));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int ma = 0;

        for (int j = 0; j < m; j++)
        {
            ma = max(ma, a[i][j]);
            if (a[i][j] == ma) t[i][j] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int ma = 0;

        for (int j = m - 1; j >= 0; j--)
        {
            ma = max(ma, a[i][j]);
            if (a[i][j] == ma) t[i][j] = true;
        }
    }

    for (int j = 0; j < m; j++)
    {
        int ma = 0;

        for (int i = 0; i < n; i++)
        {
            ma = max(ma, a[i][j]);
            if (a[i][j] == ma) t[i][j] = true;
        }
    }

    for (int j = 0; j < m; j++)
    {
        int ma = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            ma = max(ma, a[i][j]);
            if (a[i][j] == ma) t[i][j] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (t[i][j]) 
            {
                res++;
            }
        }
    }

    cout << res;

    return 0;
}