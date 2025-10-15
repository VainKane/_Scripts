#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
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

int const N = 3e5 + 5;

int n;
vector<int> adj[N];

int f[N];
int r[N];

bool DFS(int u, int p, int &dia)
{
    vector<pair<int, int>> d = {0, 0};

    for (auto &v : adj[u]) if (v != p)
    {
        if (!DFS(v, u, dia)) return false;
        
        maxi(f[u], f[v] + 1);
        maxi(r[u], max(f[u], r[v]));
        d.push_back({f[v] + 1, v});
    }

    sort(all(d), greater<int> ());
    bool cut = false;

    FOR(i, 1, sz(d) - 1)
    {
        if (d[i].F + d[i - 1].F > dia)
        {
            if (cut) return false;
            if (r[d[i].S] + r[d[i + 1].S] > dia) return false;
            cut = true;
        }
        else
        {
            f[u] = d[i].F;
            r[u] = r[]
            break;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int l = 1;
    int r = n;
    int res = r;

    while (l <= r)
    {
        int mid = (l + r) >> 1;

    }

    return 0;
}