#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
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

int const N = 2e5 + 5;
int const BK = 2;
int bkId[N];

int n, q;
int a[N];

long long pre[N];
long long lz[BK + 5];

void Init()
{
    pre[0] = a[0];

    FOR(i, 1, n - 1)
    {
        pre[i] = pre[i - 1] + a[i];
        bkId[i] = i / BK;
    }
}

void Lazy(int &id)
{
    if (lz[id] == 0) return;
    FOR(i, BK * id, min(n, BK * (id + 1)) - 1) pre[i] += lz[id];
    lz[id] = 0;
}

void ManualUpdate(int l, int r, int &x)
{
    Lazy(bkId[l]);
    FOR(i, l, r) pre[i] += x;
}

void Update(int l, int r, int x)
{
    if (l > r) return;
    if (bkId[l] == bkId[r]) 
    {
        ManualUpdate(l, r, x);
        return;
    }

    FOR(i, bkId[l] + 1, bkId[r] - 1) lz[i] += x;
    ManualUpdate(l, BK * (bkId[l] + 1) - 1, x);
    ManualUpdate(BK * bkId[r], r, x);
}

int Get()
{
    int idx = 0;

    while (true)
    {
        idx = lower_bound(pre + idx, pre + n, 2 * pre[idx] + lz[bkId[idx]]) - pre;
        if (idx == n) break;
        if (pre[idx] + lz[bkId[idx]] == 2 * (pre[idx - 1] + lz[bkId[idx - 1]])) return idx + 1;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    REP(i, n) cin >> a[i];

    Init();

    while (q--)
    {
        int p, x;
        cin >> p >> x;
        p--;

        Update(p, n - 1, x - a[p]);
        a[p] = x;
        cout << Get() << '\n';
    }

    return 0;
}