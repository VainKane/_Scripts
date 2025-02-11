#include <bits/stdc++.h>

using namespace std;

int a[509][509];
long long p[509][509];

int n;
int m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];

            if (i == 0 || j == 0)
            {
                p[i][j] = a[i][j];
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j]; 
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
    }

    return 0;
}