#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define all(v) v.begin(), v.end()
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

int const N = 1e5 + 5;

int n;
int a[N];
int cnt[N];

int last[N], nxt[N];
bool rep[N];

int mode = 0;
int pos;

void Init()
{
    vector<int> vals;

    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) 
    {
        a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
        maxi(mode, ++cnt[a[i]]);
        rep[cnt[a[i]]] = true;
    }

    memset(last, 0x3f, sizeof last);
    FORD(i, n, 1)
    {
        nxt[i] = last[a[i]];
        last[a[i]] = i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    Init();

    FORD(i, n, 1) if (cnt[a[i]] == mode && !rep[cnt[a[i]]])
    {
        cout << i << ' ' << i + 1;
        return 0;
    }

    pair<int, int> res;
    FOR(l, 1, n) if (cnt[a[l]] == mode)
    {
        int r = l;
        int maxIdx = nxt[l];

        while (cnt[a[r + 1]] == mode && r + 1 < maxIdx) 
        {
            mini(maxIdx, nxt[++r]);
        }

        if (maxi(res.S, r - l + 1) || res.S == r - l + 1) res.F = l;
        l = r;
    }

    cout << res.F << ' ' << res.F + res.S - 1;

    return 0;
}