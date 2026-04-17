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

struct SegmentTree
{
    vector<long long> t;
    vector<long long> lz;
    int n;
    
    void Build(int v, int l, int r, long long a[])
    {
        if (l == r)
        {
            t[v] = a[l];
            return;
        }

        int mid = (l + r) >> 1;
        Build(v << 1, l, mid, a);
        Build(v << 1, mid + 1, r, a);

        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }

    SegmentTree(int _n = 0, long long pre[] = {})
    {
        n = _n;
        t.assign(4 * n, 0);
        lz.assign(4 * n, 0);
        if (n) Build(1, 1, n, pre);
    }

    void Lazy(int v)
    {
        if (lz[v])
        {
            FOR(u, v << 1, v << 1 | 1)
            {
                t[u] += lz[v];
                lz[u] += lz[v];
            }

            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v] += val;
            lz[v] += val;
            return;
        }

        Lazy(v);
        int mid = (l + r) >> 1;

        Update(v << 1, l, mid, left, right, val);
        Update(v << 1 | 1, mid + 1, r, left, right, val);

        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }

    int Search(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left || t[v] < val) return 0;
        if (l == r) return l;

        Lazy(v);
        int mid = (l + r) >> 1;
    
        int pos = Search(v << 1, l, mid, left, right, val);
        if (pos) return pos;
        return Search(v << 1 | 1, mid + 1, r, left, right, val);
    }

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }

    int Search(int l, int r, int val)
    {
        if (l > r) return 0;
        return Search(1, 1, n, l, r, val);
    }
};

int const N = 1e5 + 5;

int n, q;
pair<int, int> s[N];
long long pre[N];

bool mark[N];

int res[N];
SegmentTree it;
int id[N];

void SolveTrace()
{
    int a, b, k;
    cin >> a >> b >> k;

    while (k--)
    {
        int i; cin >> i;
        mark[i] = true;
    }

    vector<int> v;
    FOR(i, 1, n) if (!mark[i]) v.push_back(id[i]);
    sort(all(v));

    int cnt = 0;
    for (auto &i : v)
    {
        if (a >= s[i].F) res[s[i].S] = 1, a -= s[i].F;
        else if (b >= s[i].F) res[s[i].S] = 2, b -= s[i].F;
        cnt += res[s[i].S] != 0;
    }

    cout << cnt << '\n';
    FOR(i, 1, n) cout << res[i];
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> s[i].F, s[i].S = i;

    sort(s + 1, s + n + 1);
    FOR(i, 1, n) pre[i] = pre[i - 1] + s[i].F;
    FOR(i, 1, n) id[s[i].S] = i;

    it = SegmentTree(n, pre);

    SolveTrace();
    q--;

    while (q--)
    {
        int a, b, k;
        cin >> a >> b >> k;
    
        vector<int> v;
        while (k--)
        {
            int i; cin >> i;
            v.push_back(id[i]);
        }

        for (auto &i : v) it.Update(i, it.n, -s[i].F);
        int pos1 = it.Search(1, n, a);
        
        for (auto &i : v) it.Update(i, it.n, s[i].F);
    }

    return 0;
}