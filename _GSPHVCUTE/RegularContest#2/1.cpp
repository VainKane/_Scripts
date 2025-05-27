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

long long dp[(1 << 21) + 5][K];

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

void Dijkstra(int s, long long d[], int a[], int c[N][N], int n)
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

        for (int i = 1; i <= n; i++)
        {
            int v = a[i];
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

    b[1] = 1;
    for (int i = 2; i <= k + 1; i++) cin >> b[i];

    for (int i = 1; i <= k + 1; i++)
    {
        int x = b[i];

        memset(d[x], 0x3f, sizeof d[x]);
        Dijkstra(x, d[x], a, c, n);
    }

    memset(dp, 0x3f, sizeof dp);
    dp[1 << 0][0] = 0;

    for (int mask = 0; mask < mk(k + 1); mask++)
    {
        for (int i = 0; i < k + 1; i++)
        {
            if (bit(i, mask)) continue;
            for (int j = 0; j < k + 1; j++)
            {
                if (!bit(j, mask)) continue;
                dp[on(i, mask)][i] = min(dp[on(i, mask)][i], dp[mask][j] + d[b[j + 1]][b[i + 1]]);
            }
        }
    }

    for (int i = 1; i < k + 1; i++)
    {
        res = min(res, dp[mk(k + 1) - 1][i] + d[b[i + 1]][1]);
    }

    cout << res;
}