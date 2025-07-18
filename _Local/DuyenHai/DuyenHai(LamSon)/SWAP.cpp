#include <bits/stdc++.h>

using namespace std;

#define name "SWAP"

int const N = 1e2 + 5;

int n;
int k;

int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (k == 0) break;

        int idx = max_element(a + i, a + min(i + k, n) + 1) - a;
        if (idx == i) continue;
        
        for (int j = idx - 1; j >= i; j--) swap(a[j], a[j + 1]);
        k -= idx - i;
    }

    for (int i = 1; i <= n; i++) cout << a[i] << ' ';

    return 0;
}