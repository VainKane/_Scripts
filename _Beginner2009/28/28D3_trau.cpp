#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define F first
#define S second

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n;
int a[N];

vector<int> b;

int f[N];
int g[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b.push_back(a[i]);
    }

    sort(all(b));
    b.erase(unique(all(b)), b.end());

    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] <= a[j]) continue;

            if (f[i] < f[j] + 1) g[i] = g[j];
            else if (f[i] == f[j] + 1) 
            {
                g[i] += g[j];
                g[i] %= MOD;
            }  

            f[i] = max(f[i], f[j] + 1);
        }
    }

    return 0;
}