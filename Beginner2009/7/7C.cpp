#include <bits/stdc++.h>

using namespace std;

int m;
int n;

int a[15];
int x[15];
bool used[15];
long double avg;
long double res;
long double sum;
long double mi;

void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!used[j])
        {
            used[j] = true;
            x[i] = j;

            if (i == n)
            {
                res = min(res, sum);
            }
            else 
            {
                Try(i + 1);
            }

            used[j] = false; 

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(5);

    while (cin >> m)
    {
        cin >> n;

        sum = avg = 0;
        mi = res = INT_MAX;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            avg += a[i];
        }

        for (int i = 1; i <= n; i++)
        {
            mi = min(mi, abs(a[i] - avg));
        }

        avg /= m;

        Try(1);

        cout << res << '\n';
    }

    return 0;
}