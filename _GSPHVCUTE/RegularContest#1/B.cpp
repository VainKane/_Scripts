#include <bits/stdc++.h>

using namespace std;

#define name "weather"

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

string s;
string a[9] = {"gspvhcute", "N", "E", "W", "S", "NW", "WS", "SE", "EN"};

int dp[N];

int main()
{
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> s;
    s = " " + s;
    int n = s.size() - 1;

    string str = "";

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] += dp[i - 1];
        dp[i] %= MOD;

        for (int j = 5; j <= 8; j++)
        {
            str = "";
            str += s[i - 1];
            str += s[i];

            if (str != a[j]) continue;
            dp[i] += dp[i - 2];
            dp[i] %= MOD;
        }
    }

    // for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
    cout << dp[n];
}