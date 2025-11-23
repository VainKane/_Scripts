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
 
int n;
long long k;
vector<int> segments;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    cin >> n >> k;
 
    int len = n;
 
    while (k)
    {
        while (1LL * len * (len - 1) / 2 > k) len--;
        segments.push_back(len);
        k -= 1LL * len * (len - 1) / 2;
    }
 
    vector<int> res;
 
    int idx = 1;
    for (auto &len : segments)
    {
        int l = idx;
        int r = idx + len - 1;
        idx = r + 1;
 
        FORD(i, r, l) res.push_back(i);
    }
 
    if (sz(res) < n) FOR(i, idx, n) res.push_back(i);
 
    if (sz(res) > n) swap(res[0], res[sz(res) - 1]);
    for (auto &x : res) if (x <= n) cout << x << ' ';
 
    return 0;
}
