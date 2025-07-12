#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "MAXPATH"

struct Edge
{
    int v, w;
};

int const N = 1e5 + 5;

int n, m;
vector<Edge> adj[N];
bool visted[N];

double res = 0;
int cnt = 0;

bool Check(int d, int s, int t) // s -> t (>= d)
{
    memset(visted, false, sizeof visted);
    queue<int> q;
    q.push(s);

    visted[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto e : adj[u]) if (e.w >= d && !visted[e.v])
        {
            visted[e.v] = true;
            q.push(e.v);

            if (e.v == t) return true;
        }
    }

    return false;
}

int GCD(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    FOR(u, 1, n) FOR(v, u + 1, n) if (GCD(u, v) == 1)
    {
        int l = 1;
        int r = 1e9;

        int k = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (Check(mid, u, v))
            {
                k = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        res += k;
        cnt++;
    }
    
    cout << fixed << setprecision(2) << res / cnt;


    return 0;
}