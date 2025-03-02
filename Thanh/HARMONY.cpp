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
int ma = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int u = GCD(a[i], a[j]);
            if (u > ma)
            {
                ma = u;
                res = make_pair(min(i, j), max(i, j));
            }
        }
    }

    cout << res.first << ' ' << res.second;

    return 0;
}