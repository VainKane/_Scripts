#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 509;

int n, m;
bool c1[N][N];
bool c2[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        c1[u][v] = true;
    }
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        c2[u][v] = true;
    }

    FOR()

    return 0;
}