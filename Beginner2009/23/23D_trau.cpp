#include <bits/stdc++.h>

using namespace std;

int const MOD = 2017;
int const N = 59;

int n;
int m;
int k;

vector<int> adj[N];
int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    
    while (m--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dp[1][1] = 1;

    for (int i = 1; i <= k; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (auto v : adj[u])
            {
                dp[i][u] = (dp[i][u] + dp[i - 1][v]) % MOD;
            }
        }
    }

    cout << dp[k][n];

    return 0;
}