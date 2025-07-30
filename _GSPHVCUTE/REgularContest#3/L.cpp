#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "sort"

int const N = 5009;

int n;
int a[N], c[N];

long long pre[N];

int GetSum(int l, int r)
{
    if (l > r) swap(l, r);
    return pre[r] - pre[l - 1];
}

long long Cal()
{
    FOR(i, 1, n) pre[i] = pre[i - 1] + c[i];
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n - 1) cin >> c[i];



    return 0;
}