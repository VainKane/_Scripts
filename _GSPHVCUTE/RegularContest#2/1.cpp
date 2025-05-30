#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define name "banhkhuc"

int const N = 509;
int const K = 25;

int n, k;
int a[N];
int b[N];

int c[N][N];
long long d[N][N];

long long dp[(1 << 20) + 5][K];

long long res = 1e18;

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

int off(int i, int mask)
{
    return mask & (~(1 << i));
}

int on(int i, int mask)
{
    return mask | (1 << i);
}

int mk(int i) 
{
    return (1 << i);
}

void Dijkstra(int s, long long d[])
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});
    d[s] = 0;

    while (!pq.empty())
    {
        int u = pq.top().S;
        long long du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (int v = 1; v <= n; v++)
        {
            int w = c[u][v];

            if (v == u) continue;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cin >> c[i][j];
        a[i] = i;
    }

    for (int i = 1; i <= k; i++) cin >> b[i];

    b[0] = 1;
    for (int i = 0; i <= k; i++)
    {
        int x = b[i];

        memset(d[x], 0x3f, sizeof d[x]);
        Dijkstra(x, d[x]);
    }

    memset(dp, 0x3f, sizeof dp);
    for (int i = 0; i < k; i++) 
    {
        dp[1 << i][i] = d[1][b[i + 1]];
    }

    for (int mask = 0; mask < mk(k); mask++)
    {
        for (int i = 0; i < k; i++)
        {
            if (bit(i, mask)) continue;
            for (int j = 0; j < k; j++)
            {
                if (!bit(j, mask)) continue;
                dp[on(i, mask)][i] = min(dp[on(i, mask)][i], dp[mask][j] + d[b[j + 1]][b[i + 1]]);
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        res = min(res, dp[mk(k) - 1][i] + d[b[i + 1]][1]);
    }

    cout << res;
}