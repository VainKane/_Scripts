#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 8009;
int const oo = 1e9 + 1;

int n;
int a[N], b[N];

vector<int> vals;
long long cnt[N];

int f[N][N];
pair<int, long long> res;

int GetId(int const &x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Compress()
{
    FOR(i, 1, n) 
    {
        vals.push_back(a[i]);
        vals.push_back(b[i]);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) 
    {
        a[i] = GetId(a[i]);
        b[i] = GetId(b[i]);
    }
}

void Sub2()
{
    FOR(i, 1, n) f[i][1] = a[i], cnt[a[i]]++;
    FOR(i, 1, n) f[1][i] = b[i], cnt[b[i]]++;
    cnt[a[1]]--;

    FOR(i, 2, n) FOR(j, 2, n)
    {
        f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        cnt[f[i][j]]++;
    }

    FORD(i, sz(vals), 0) if (maxi(res.S, cnt[i])) res.F = vals[i - 1];
    cout << res.F << ' ' << res.S;

    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], vals.push_back(a[i]);
    FOR(i, 1, n) cin >> b[i], vals.push_back(b[i]);

    Compress();
    Sub2();

    return 0;
}