#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "MATCH"

int const N = 1e6 + 5;

int n, m, q;
int a[N], b[N];
int pos[N];

bool used[N];

bool Sub2(int l, int r)
{
    memset(used, false, sizeof used);
    bool ok = true;

    FOR(i, l, r) 
    {
        if (used[a[i]]) return false;
        used[a[i]] = true;
    }

    FOR(i, l, r - 1)
    {
        if (a[i] != a[i + 1] - 1)
        {
            if (!ok) return false;
            else ok = false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i], pos[b[i]] = i;

    FOR(i, 1, n) a[i] = pos[a[i]];

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        bool res = false;
        res = Sub2(l, r);
        
        cout << (res ? "YES\n" : "NO\n");
    }

    return 0;
}