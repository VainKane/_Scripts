#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define F first
#define S second

int const N = 1e6 + 5;

int n;
pii a[N];

int GCD(int a, int b)
{
    int r = a % b;
    if (!r) return b;
    
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int ma = 0;
int x;
int y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        a[i] = {x, i};
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int gcd = GCD(a[i].F, a[j].F);
            if (gcd > ma)
            {
                ma = gcd;
                x = a[i].S;
                y = a[j].S;
            }
        }
    }

    cout << x << ' ' << y;

    return 0;
}