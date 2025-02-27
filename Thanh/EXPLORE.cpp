#include <bits/stdc++.h>

using namespace std;

int n;
int w;
int x[29];
pair<int, int> a [(int)1e4 + 10];

long long res = 0;

void Try(int pos)
{
    if (pos > n)
    {
        int m = 0;
        int v = 0;

        for (int i = 1; i <= n; i++)
        {
            if (x[i])
            {
                m += 1ll * a[i].first;
                v += a[i].second;
            }
        }
        
        if (m <= w)
        {
            res = max(res, 1ll * v);
        }

        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        x[pos] = i;
        Try(pos + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    Try(1);

    cout << res;

    return 0;
}