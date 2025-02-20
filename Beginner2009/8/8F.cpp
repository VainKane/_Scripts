#include <bits/stdc++.h>

using namespace std;

int n;
int w;
int h;

pair<int, int> a[(int)1e5 + 10];
long double const pre = 1e-6;

bool Check(long double k)
{
    long double wide = 0;
    long double height = 0;
    int maxh = 0;

    for (int i = 0; i < n; i++)
    {
        if (wide + a[i].first * k <= w + pre)
        {
            wide += a[i].first * k;
            maxh = max(maxh, a[i].second);
        }
        else
        {
            height += maxh * k;
            wide = a[i].first * k;
            maxh = a[i].second;
            if (height > h + pre) return false;
        }
    }

    return (height + maxh * k) <= h + pre;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(6);
    
    cin >> n >> w >> h;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    long double l = 0;
    long double r = 1e9;
    long double mid;
    long double res = 0;

    while (r - l > pre)
    {
        mid = l + (r - l) / 2;

        if (Check(mid))
        {
            res = mid;
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    cout << res;

    return 0;
}