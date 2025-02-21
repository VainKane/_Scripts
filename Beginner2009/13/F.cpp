#include <bits/stdc++.h>

using namespace std;

int n;
int d;
pair<int, int> a[50009];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);

    cout << '\n';

    for (int i = 0; i < n; i++) cout << a[i].first << ' ' << a[i].second << '\n';

    return 0;
}