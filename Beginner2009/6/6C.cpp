#include <bits/stdc++.h>

using namespace std;

int n;
int m;

int a[20][20];

int res = INT_MAX;
int w;

int x[20][20];

int cnt = 0;
bool used[20];
int cmin [20];

int sum = 0;

void Try(int i, int k)
{
    cnt++;
    for (int j = x[k][i - 1] + 1; j <= m - w + i; j++)
    {
        if (!used[j])
        {
            used[j] = true;

            x[k][i] = j;

            for (int u = 1; u <= k - 1; u++)
            {
                for (int p = 1; p <= w; p++)
                {
                    sum += a[x[u][p]][x[k][i]];
                }
            }

            if (i == w)
            {
                int s = sum;

                for (int u = 1; u <= k; u++)
                {
                    for (int p = 1; p <= w; p++)
                    {
                        s += cmin[x[u][p]];
                    }
                }

                if (k == n)
                {
                    res = min(res, sum);
                }
                else if (s < res)
                {
                    Try(1, k + 1);
                }
            }
            else
            {
                Try(i + 1, k);
            }

            used[j] = false;
            
            for (int u = 1; u <= k - 1; u++)
            {
                for (int p = 1; p <= w; p++)
                {
                    sum -= a[x[u][p]][x[k][i]];
                }
            }
        }  
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;

    for (int i = 1; i <= m; i++)
    {
        cmin[i] = INT_MAX;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];

            if (i != j)
            {
                cmin[i] = min(cmin[i], a[i][j]);
            }
        }
    }

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    w = m / n;

    Try(1, 1);

    cout << res << '\n';
    cout << cnt;

    return 0;
}