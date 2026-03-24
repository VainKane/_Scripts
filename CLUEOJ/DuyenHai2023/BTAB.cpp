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

int m, n;
vector<vector<int>> a, pre;
vector<vector<bool>> visited;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;

    a.assign(m + 5, vector<int> (n + 5));
    pre.assign(m + 5, vector<int> (n + 5));
    visited.assign(m + 5, vector<bool> (n + 5));

    FOR(i, 1, m) FOR(j, 1, n) 
    {
        cin >> a[i][j];
        if (a[i][j] != -1) visited[i][j] = true;
        pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (a[i][j] == -1);
    }

    FOR(i, 1, m) FOR(j, 1, n) if (!visited[i][j])
    {
        
    }

    return 0;
}