#include <bits/stdc++.h>

using namespace std;

#define name "CSBN"

int const N = 1e7 + 5;

int n;
int a[N];

long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++) 
        {
            res += a[i] == a[j];
        }
    }

    cout << res;

    return 0;
}