#include <bits/stdc++.h>

using namespace std;

int n;
int a[(int)1e6 + 10];

int GCD(int a, int b)
{
    int r = a % b;
    if (r == 0) return b;

    while (r)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

pair<int, int> res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // if (n <= 20)
    // {
    //     for (int i = 1; i <= n; i++)
    //     {
    //         for (int j = i + 1; j <= n; j++)
    //         {
    //             int u = GCD(a[i], a[j]);
    //             if (u > ma)
    //             {
    //                 ma = u;
    //                 res = make_pair(min(i, j), max(i, j));
    //             }
    //         }
    //     }
    // }
    // else
    // {

    // }
    for (int i = 1; i <= 50; i++)
    {
        int cnt = 1;
        int p[3];

        for (int j = 1; j <= n; j++)
        {
            if (a[j] % i == 0)
            {
                p[cnt] = j;
                cnt++;
            }
            if (cnt == 3) break;
        }

        if (cnt == 3)
        {
            res.first = p[1];
            res.second = p[2];
        }
    }

    cout << res.first << ' ' << res.second;

    return 0;    
}