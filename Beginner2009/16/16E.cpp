#include <bits/stdc++.h>

using namespace std;

int const N = 1e6;
int const maxLog = 20;

int n;
int k;

int p[2 * N + 2];
int st[2 * N + 3][maxLog + 3];

int res = 1e7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("16E.inp", "r", stdin);
    // freopen("16E.out", "w", stdout);

    cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        int l, r;
        cin >> l >> r;

        if (l > r) r += n;

        p[l] = max(p[l], r);
        if (l <= r) p[l + n] = max(p[l + n], r + n);
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        p[i] = max(p[i], p[i - 1]);
        st[i][0] = p[i] + 1;
    }

    for (int j = 1; j <= maxLog; j++)
    {
        for (int i = 1; i <= 2 * n; i++)
        {
            st[i][j] = st[st[i][j - 1]][j - 1];
        }
    }


    for (int i = 1; i <= n; i++)
    {
        int x = i;
        int end = i + n;
        int cnt = 0;    
        
        for (int j = maxLog; j >= 0; j--)
        {
            if (st[x][j] < end && st[x][j] > x)
            {
                x = st[x][j];
                cnt += (1 << j);
            }
        }

        if (st[x][0] >= end) res = min(res, cnt + 1);
    }

    if (res == 1e7)
    {
        cout << "impossible";
        return 0;
    }

    cout << res;

    return 0;
}