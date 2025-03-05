#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int res = 5009;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> s;

    s = " " + s;

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= min(i - 1, n - i); j++)
        {
            if (s[i - j] == s[i + j]) cnt++;
        }
        res = min(res, n - cnt);

        cnt = 0;
        if (s[i] == s[i - 1])
        {
            for (int j = 1; j <= min(i - 2, n - i); j++)
            {
                if (s[i - j - 1] != s[i + j])cnt++;
            }
            res = min(res, n - 2 - cnt);
        }
    }

    cout << res;

    return 0;
}