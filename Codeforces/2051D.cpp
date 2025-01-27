#include <bits/stdc++.h>

using namespace std;

int t;

int n;
long long x;
long long y;

long long sum;

int a[(int)2e5 + 10];

int cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> x >> y;

        sum = 0;
        cnt = 0;

        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
            sum += 1LL * a[i];
        }

        sort(a, a + n);

        int l = 0;
        int r = n - 1;

        while (l < r)
        {
            int s = sum - a[l] - a[r];

            
        }

        cout << cnt << '\n';
    }

    return 0;
}