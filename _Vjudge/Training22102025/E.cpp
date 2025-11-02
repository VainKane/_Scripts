#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

int const N = 3e5 + 5;

int n;
int cnt[N];

long long f[N];
long long g[N];

long long C(int k, int n)
{
    if (n < k) return 0;
    return (f[n] / f[n - k]) / f[k];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        cnt[x]++;
    }

    FOR(i, 1, 3e5) for (int j = 2 * i; j <= 3e5; j += i) cnt[i] += cnt[j];
    
    f[0] = 1;
    FOR(i, 1, 3e5) f[i] = f[i - 1] * i;

    FOR(k, 1, 7)
    {
        FORD(i, 3e5, 1) 
        {
            g[i] = C(k, cnt[i]);
            for (int j = 2 * i; j <= 3e5; j += i) g[i] -= g[j];
        } 

        if (g[1])
        {
            cout << k;
            return 0;
        }
    }
    
    cout << -1;

    return 0;
}