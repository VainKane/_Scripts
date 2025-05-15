#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;
int const B1 = 449;
int const B2 = 457;

int const N = 1009;

int preHash[N][N];
int powB1[N];
int powB2[N];

int n;
int m;
int a;
int b;
char s[N][N];

unordered_map<int, int> cntHash;

vector<pair<int, int>> res;

int GetHash(int u, int v, int p, int q)
{
    int res = preHash[u][v];

    int t1 = ( 1ll * preHash[p - 1][v] * powB1[u - p + 1] ) % MOD;
    int t2 = ( 1ll * preHash[u][q - 1] * powB2[v - q + 1] ) % MOD;
    long long t3 = 1ll * preHash[p - 1][q - 1] * powB1[u - p + 1];
    t3 %= MOD;
    t3 *= powB2[v - q + 1];
    t3 %= MOD;

    res -= t1;
    res = (res + 1LL * MOD * MOD) % MOD;
    res -= t2;
    res = (res + 1LL * MOD * MOD) % MOD;
    res = (res + t3) % MOD;

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("17E.inp", "r", stdin);
    // freopen("17E.out", "w", stdout);

    cin >> m >> n;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> s[i][j];
        }
    }

    cin >> a >> b;

    for (int i = 1; i <= m; i++)
    {
        preHash[i][1] = ( 1ll * preHash[i - 1][1] * B1 + s[i][1] ) % MOD;
    }
    for (int j = 1; j <= n; j++)
    {
        preHash[1][j] = ( 1ll * preHash[1][j - 1] * B2 + s[1][j] ) % MOD;
    }

    powB1[0] = powB2[0] = 1;
    for (int i = 1; i <= max(m, n); i++)
    {
        powB1[i] = ( 1ll * powB1[i - 1] * B1 ) % MOD;
        powB2[i] = ( 1ll * powB2[i - 1] * B2 ) % MOD;
    }

    for (int i = 2; i <= m; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            int t1 = ( 1ll * preHash[i - 1][j] * B1) % MOD;
            int t2 = ( 1ll * preHash[i][j - 1] * B2 ) % MOD;
            int t3 = ( 1ll * preHash[i - 1][j - 1] * B1 * B2 ) % MOD;
            
            preHash[i][j] = t1;
            preHash[i][j] = ( 1ll * preHash[i][j] + t2 ) % MOD;
            preHash[i][j] -= t3;
            preHash[i][j] += MOD;
            preHash[i][j] %= MOD;
            preHash[i][j] += s[i][j];
            preHash[i][j] %= MOD;
        }
    }


    for (int i = 1; i <= m - a + 1; i++)
    {
        for (int j = 1; j <= n - b + 1; j++)
        {
            int val = GetHash(i + a - 1, j + b - 1, i, j);
            cntHash[val]++;
        }
    } 

    int ma = 0;
    int k = 0;

    for (auto p : cntHash)
    {
        if (p.second > ma)
        {
            ma = p.second;
            k = p.first;
        }
    }

    for (int i = 1; i <= m - a + 1; i++)
    {
        for (int j = 1; j <= n - b + 1; j++)
        {
            int val = GetHash(i + a - 1, j + b - 1, i, j);
            if (val == k)
            {
                res.push_back({i, j});
            }
        }
    } 

    cout << a << ' ' << b << '\n';
    for (int i = res[0].first; i < res[0].first + a; i++)
    {
        for (int j = res[0].second; j < res[0].second + b; j++)
        {
            cout << s[i][j];
        }
        cout << '\n';
    }    
    cout << res.size() << '\n';
    for (auto val : res) cout << val.first << ' ' << val.second << '\n';

    return 0;
}