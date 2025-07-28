#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1 << (i))
#define name "goodbye22maxand"

int const N = 1e6 + 5;

bool used[N];

vector<int> Get(int l, int r, int idx)
{
    vector<int> v;
    FOR(i, l, r) if (!BIT(idx, i) && ! used[i]) v.push_back(i);
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    int q; cin >> q;
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        
        memset(used, false, sizeof used);
        int res = 0;

        FORD(i, 31 - __builtin_clz(r), 0)
        {
            vector<int> v = Get(l, r, i);
            if (k < v.size()) continue;

            for (auto x : v) used[x] = true;
            res |= MK(i);
            k -= v.size();
        }

        cout << res << '\n';
    }

    return 0;
}