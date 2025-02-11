#include <bits/stdc++.h>

using namespace std;

struct Paper
{
    int x1;
    int x2;
    int y1;
    int y2;
};

int n;
Paper a[109];

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            res += Area(a[i], a[j]);
        }
    }

    cout << res;

    return 0;
}