#include <bits/stdc++.h>

using namespace std;

int n;
int a[(int)1e5 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int x = (n - 1) / 2;

    int k = 0;
    int j = x;

    cout << x << '\n';

    for (int i = 0; i < n / 3; i++)
    {
        if (j < n - 1 && k < x) cout << a[j] << ' ' << a[k] << ' ' << a[j + 1];
    }

    return 0;
}