#include <bits/stdc++.h>

using namespace std;

#define name "BAI04"

int const N = 1e5 + 5;

int n;
int a[N];

int cnt1[N];
int cnt2[N];
int cnt3[N];

void Sub1()
{
    long long res = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if ((*max_element(a + i, a + j + 1) - *min_element(a + i, a + j + 1)) % 2 == 0) res++;
        }
    }

    cout << res;
}

void Sub2()
{
    long long res = 0;

    int last1 = 0;
    int last2 = 0;
    int last3 = 0;

    for (int i = 1; i <= n; i++)
    {
        cnt1[i] = cnt1[i - 1];
        cnt2[i] = cnt2[i - 1];
        cnt3[i] = cnt3[i - 1];

        if (a[i] == 1) cnt1[i]++;
        if (a[i] == 2) cnt2[i]++;
        if (a[i] == 3) cnt3[i]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 3)
        {
            if (last1) res += cnt2[last1];
            else res += cnt2[i];


            last3 = i;
        }
        if (a[i] == 2)
        {
            if (last3) res += cnt1[last3];
            else res += cnt1[i];

            if (last1) res += cnt3[last1];
            else res += cnt3[i];

            last2 = i;
        }
        if (a[i] == 1)
        {
            if (last3) res += cnt2[last3];
            else res += cnt2[i];

            if (last2) res += cnt1[last2];
            else res += cnt1[i - 1];

            last1 = i;
        }
    }

    cout << ( 1ll * n * (n - 1) ) / 2 + n - res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // if (n <= 4000) Sub1();
    // else Sub2();

    Sub2();

    return 0;
}