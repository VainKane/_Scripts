#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 3e5 + 5;

int n;
int deg[N];

vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        deg[u]++; deg[v]++;
    }

    FOR(u, 1, n) if (deg[u] == 1) v.push_back(u);

    cout << (sz(v) + 1) / 2 << '\n';

    // for (int i = 0; i < sz(v) - 1; i += 2) cout << v[i] << ' ' << v[i + 1] << '\n';
    // if ((sz(v) & 1) && sz(v) >= 3) cout << v[sz(v) - 1] << ' ' << v[sz(v) - 2];

    for (auto &u : v) cout << u << ' ';

    return 0;
}