#include <bits/stdc++.h>

using namespace std;

#define left sdjf
#define right sdf

int const N = 3e5 + 5;

int n, k;
int a[N];
int pre[N];

int left = 0;
int right = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (a[i] ^ 1);

    for (int i = 1; i <= n; i++)
    {
        int l = i;
        int r = n;
        int 3;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            
            if (pre[mid] - pre[i - 1] <= k)
            {
                bound = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        if (bound - i > right - left) 
        {
            left = i;
            right = bound;
        }
    }

    cout << right - left + 1 << '\n';

    for (int i = 1; i <= n; i++)
    {
        if (i >= left && i <= right) a[i] = 1;
        cout << a[i] << ' ';
    }

    return 0;
}