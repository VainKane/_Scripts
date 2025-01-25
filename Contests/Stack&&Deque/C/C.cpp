#include <bits/stdc++.h>

using namespace std;

struct Cow
{
    int x;
    int h;

    bool left = false;
    bool right = false;
};

bool cmp(Cow a, Cow b)
{
    if (a.h < b.h) return true;
    return false;
}

int Lower_Bound(Cow cows[], int tar, int l, int r)
{
    int mid = r + 1;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (cows[mid].h <= tar)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return mid;
}

int n;
int d;

Cow cows[(int)1e5 + 10];

int cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;

    for (int i = 0; i < n; i++) cin >> cows[i].x >> cows[i].h;

    sort(cows, cows + n, cmp);

    for (int i = 0; i < n; i++)
    {
        int pos = Lower_Bound(cows, 2 * cows[i].h, i + 1, n - 1);

        for (int j = pos; j < n; j++)
        {
            if (abs(cows[j].x - cows[i].x) <= d)
            {
                if (cows[j].x > cows[i].x) cows[i].right = true;
                else cows[i].left = true;
            }


        }
        if (cows[i].left && cows[i].right) cnt++;
    }

    cout << cnt;

    return 0;
}
