#include <bits/stdc++.h>

using namespace std;

int n;
int w;
int h;

pair<int, int> a[(int)1e5 + 10];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second > b.second) return true;
    else if (a.second == b.second) return a.first < b.first;
    return false;
}

bool Check(long double k)
{
    long double wide = 0;
    long double height = 0;
    int maxh = 0;

    for (int i = 0; i < n; i++)
    {
        if (wide + a[i].first * k <= w)
        {
            wide += a[i].first * k;
            maxh = max(maxh, a[i].second);
        }
        else if (maxh != 0)
        {
            height += maxh * k;
            wide = 0;
            maxh = 0;
            i--;
            if (height > h) return false;
        }
        else
        {
            return false;
        }
    }

    return (height + maxh * k <= h);
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

    sort(a, a + n, cmp);

    long double l = 0;
    long double r = LLONG_MAX;
    long double mid;
    long double res = 0;

    while (r - l > 1e-7)
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