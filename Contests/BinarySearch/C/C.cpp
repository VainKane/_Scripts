#include <bits/stdc++.h>

using namespace std;

struct Truck
{
    int s;
    int f;
    int c;
    int r;
};

bool Check(Truck trucks[], int vc, int d[], int m, bool isVC)
{
    for (int i = 0; i < m; i++)
    {
        int v;
        if (isVC) v = vc * trucks[i].c;
        else v = vc;

        int f = v;
        int r = trucks[i].r;

        for (int j = trucks[i].s - 1; j < trucks[i].f - 1; j++)
        {
            if (d[j] > v) return false;

            if (f >= d[j] * trucks[i].c)
            {
                f -= d[j] * trucks[i].c;
            }
            else
            {
                f = v;
                r -= 1;
                if (r < 0)
                {
//                    cout << "wrong: " << i << '\n';
                    return false;
                }
            }
        }
    }

    return true;
}

int MinVc(Truck trucks[], int d[], int l, int r, int m)
{
    int mid;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (Check(trucks, mid, d, m, true))
        {
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    return mid;
}

int MinV(Truck trucks[], int d[], int c[], int vc, int l, int r, int m)
{
//    int mid;
//
//    while (l <= r)
//    {
//        mid = (l + r) / 2;
//
//        if (Check(trucks, c[mid] * vc, d, m, false))
//        {
//            r = mid - 1;
//        }
//        else{
//            l = mid + 1;
//        }
//    }
//
//    return c[mid] * vc;

    for (int i = 0; i < m; i++)
    {
        if (Check(trucks, c[i] * vc, d, m, false))
        {
            return c[i] * vc;
        }
    }
}

int n;
int m;

int a[(int)1e3 + 10];

Truck trucks[(int)1e3 + 10];

int d[(int)1e3 + 10];
int maxd = 0;
int sumd = 0;

int c[(int)1e3 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    cin >> a[0];

    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        d[i - 1] = a[i] - a[i - 1];
        if (d[i - 1] > maxd) maxd = d[i - 1];
    }

    sumd = a[n - 1] - a[0];

    for (int i = 0; i < m; i++)
    {
        cin >> trucks[i].s >> trucks[i].f >> trucks[i].c >> trucks[i].r;
        c[i] = trucks[i].c;
    }

    int vc = MinVc(trucks, d, maxd, sumd, m);

    sort(c, c + m);

    cout << vc << ' ' << MinV(trucks, d, c, vc, 0, m - 1, m);

    return 0;
}
