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

struct Edge
{
    int u, v, p;

    int GetOther(int node)
    {
        return node ^ u ^ v;
    }

    void Input()
    {
        cin >> u >> v >> p;
        p &= 1;
    }
};

int const N = 2e5 + 5;

int n;

Edge edges[N];
vector<int> adj[N];

long long f[N][2];
long long cnt[2];

void DFS(int u, int p)
{
    vector<long long> odd, even;
    long long sumOdd = 0, sumEven = 0;
    
    for (auto &id : adj[u])
    {
        int v = edges[id].GetOther(u);
        int pt = edges[id].p;
        
        if (v == p) continue;

        long long haha[2];
        haha[0] = haha[1] = 0;
        DFS(v, u);

        REP(i, 2) 
        {
            int x = f[v][i ^ pt] + (i == pt);

            f[u][i] += x;
            cnt[i] += x;
            haha[i] += x;
        }

        even.push_back(haha[0]);
        odd.push_back(haha[1]);

        sumEven += haha[0];
        sumOdd += haha[1];
    }

    for (auto &x : even) cnt[0] += x * (sumEven - x);
    for (auto &x : odd) cnt[0] += x * (sumOdd - x);

    REP(i, sz(odd)) cnt[1] += odd[i] * (sumEven - even[i]);

    cout << "AFTER " << u << ": " << cnt[0] << ' ' << cnt[1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n - 1)
    {
        edges[i].Input();
        adj[edges[i].u].push_back(i);
        adj[edges[i].v].push_back(i);
    }

    DFS(1, -1);
    long long res = abs(cnt[0] - cnt[1]);

    // cout << cnt[0] << ' ' << cnt[1] << '\n';

    FOR(i, 1, n - 1)
    {
        edges[i].p ^= 1;
        
        cnt[0] = cnt[1] = 0;
        memset(f, 0, sizeof f);
        // DFS(1, -1);
        // if ( mini(res, abs(cnt[0] - cnt[1])) ) cout << i << ' ' << cnt[0] << ' ' << cnt[1];        
        
        // if (i == 3) FOR(u, 1, n) cout << f[u][0] << ' ';
        // if (i == 3) cout << "debug: " << cnt[0] << ' ' << cnt[1] << '\n';
        edges[i].p ^= 1;
    }

    // cout << res;
    // FOR(u, 1, n) cout << f[u][0] << ' ';

    return 0;
}