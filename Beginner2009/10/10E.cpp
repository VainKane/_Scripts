#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> a[(int)2e5 + 10];

long long x, y;
long long u, v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    x = a[1].second;
    y = a[1].second - 1;

    cout << "---------------\n";
    cout << x << ' ' << y << '\n';

    for (int i = 2; i <= n; i++)
    {
        int d = a[i].second - a[i].first;

        long long u = x;
        long long v = y;

        x = v + abs(a[i - 1].second - a[i].second) + d + 1;
        y = u + abs(a[i - 1].first - a[i].first) + d + 1;

        cout << x << ' ' << y << '\n';
    }

    return 0;
}