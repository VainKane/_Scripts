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

vector<int> vals;

struct SegmentTree
{
    vector<pair<int, long long>> t;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, {0, 0});
    }

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v].F += val;
            if (t[v].F) t[v].S = vals[r - 1] - vals[l - 1] + 1;
            // else t[v].S =
            return;
        }
    }
};

struct Event
{
    int x, y1, y2, type;

    bool operator < (Event const other) const
    {
        if (x != other.x) return x < other.x;
        return type < other.type;
    }
};

int const N = 1e5 + 5;

int k, n;

int x1[N], y1[N];
int x2[N], y2[N];

int dx[256], dy[256];

vector<Event> events;
SegmentTree it;

int GetId(int x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Compress()
{
    vals = {0, k};

    FOR(i, 1, n + 1)
    {
        vals.push_back(x1[i]);
        vals.push_back(y1[i]);
        vals.push_back(x2[i] = x1[i] + k - 1);
        vals.push_back(y2[i] = y1[i] + k - 1);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n + 1)
    {
        x1[i] = GetId(x1[i]);
        y1[i] = GetId(y1[i]);
    }

    it = SegmentTree(sz(vals));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> k >> n;

    dy['N'] = 1, dy['S'] = -1;
    dx['E'] = 1, dx['W'] = -1;

    FOR(i, 1, n)
    {
        char dir; int st;
        cin >> dir >> st;
        
        x1[i + 1] = x1[i] + dx[dir] * st;
        y1[i + 1] = y1[i] + dy[dir] * st;
    }

    Compress();

    FOR(i, 1, n)
    {
        events.push_back({x1[i], y1[i], y2[i], 1});
        events.push_back({x2[i + 1], y1[i + 1], y2[i + 1], -1});
    }

    return 0;
}