#include <bits/stdc++.h>

using namespace std;

struct Truck
{
    int s;
    int f;
    int c;
    int r;
};

int Check(Truck trucks[], int vc, int d[], int truckCount)
{
    for (int i = 0; i < truckCount; i++)
    {
        int v = vc * trucks[i].c;
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

int n;
int m;

int a[(int)1e3 + 10];

Truck trucks[(int)1e3 + 10];

int d[(int)1e3 + 10];
int maxd = 0;
int sumd = 0;

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

//    for (int i = 0; i < n - 1; i++) cout << d[i] << ' ';
//    cout << '\n';
//    cout << maxd << ' ' << sumd;

    for (int i = 0; i < m; i++) cin >> trucks[i].s >> trucks[i].f >> trucks[i].c >> trucks[i].r;

    for (int i = maxd; i <= sumd; i++)
    {
        cout << i << ' ' << Check(trucks, i, d, m) << '\n';
    }

    return 0;
}
