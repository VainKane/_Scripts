#include <bits/stdc++.h>

using namespace std;

int const N = 1e6;
int const maxLog = 20;

struct Rope
{
    int l = 0;
    int r = 0;
};

int n;
int k;
Rope a[N + 5];

int p[2 * N + 2];
int st[2 * N + 5][maxLog + 5];

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
        cin >> a[i].l >> a[i].r;
        if (a[i].l > a[i].r) a[i].r += n;

        p[a[i].l] = max(p[a[i].l], a[i].r);
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        p[i] = max(p[i], p[i - 1]);
        st[i][0] = p[i];
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        for (int j = 1; (1 << j) <= k; j++)
        {
            st[i][j] = st[st[i][j - 1] + 1][j - 1];
            if (st[i][j] <= st[i][j - 1]) st[i][j] = 0;
        }
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        int x = i;
        int end = i + n;
        int cnt = 0;    
        
        for (int j = maxLog; j >= 0; j--)
        {
            if (x >= end)
            {
                res = min(res, cnt);
                break;
            }
            if (st[x][j] != 0)
            {
                if (st[x][j] < end)
                {
                    x = st[x][j] + 1;
                    cnt += (1 << j);
                }
                else if (st[x][j] >= end)
                {
                    res = min(res, cnt + (1 << j));
                }
            }
        }

        if (x >= end)
        {
            res = min(res, cnt);
        }
    }

    // for (int i = 1; i <= 2 * n; i++)
    // {
    //     for (int j = 0; (1 << j) <= k; j++)
    //     {
    //         cout << i << ' ' << j << ' ' << st[i][j] << '\n';
    //     }
    // }

    if (res == 1e7)
    {
        cout << "impossible";
        return 0;
    }

    cout << res;

    return 0;
}