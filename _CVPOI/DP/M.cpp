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

int const N = 109;

int n;

vector<int> d;
vector<pair<int, int>> pt = {{0, 0}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        d.push_back(x);
    }

    do
    {
        REP(mask, MK(n))
        {
            int x = 0, y = 0;
            REP(i, n) 
            {
                if (BIT(i, mask)) x += d[i];
                else y += d[i];
                pt.push_back({x, y});
            }
        }

    } while (next_permutation(all(d)));

    sort(all(pt));
    pt.erase(unique(all(pt)), pt.end());

    cout << sz(pt);

    return 0;
}