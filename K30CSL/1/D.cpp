#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define F first
#define S second

int const N = 1e4 + 5;

int n;
int w;
pii a[N];
vector<pii> b;

long long dp[N];

bool cmp(pii a, pii b)
{
    return a.F < b.F;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> w;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].F >> a[i].S;
        b.push_back({a[i].F, a[i].S});
    }

    b.push_back({w, 0});
    sort(all(b), cmp);
    b.erase(unique(all(b)), b.end());

    for (int i = 1; i <= n; i++)
    {
        a[i].F = lower_bound(all(b), a[i], cmp) - b.begin() + 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = w; j >= 0; j--)
        {
            if (j >= a[i].F)
            {
                dp[j] = max(dp[j], dp[j - a[i].F] + a[i].S);
            }
        }
    }

    cout << dp[w];

    return 0;
}