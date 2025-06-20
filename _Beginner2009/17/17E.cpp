#include <bits/stdc++.h>

using namespace std;

struct Hash
{
    int a, b, c;

    bool operator < (const Hash other) const {
        if (a != other.a) return a < other.a;
        if (b != other.b) return b < other.b;
        return c < other.c;
    }

    bool operator == (const Hash other) const {
        return (a == other.a && b == other.b && c == other.c);
    }
};

int const B1 = 419;
int const B2 = 421;
int const MODA = 1e9 + 7;
int const MODB = 1e9 + 5;
int const MODC = 1e9 + 3;

int const N = 1009;

int preHashA[N][N];
int preHashB[N][N];
int preHashC[N][N];

int powB1A[N];
int powB2A[N];

int powB1B[N];
int powB2B[N];

int powB1C[N];
int powB2C[N];

int n, m;
int a, b;
char s[N][N];

map<Hash, int> cntHash;

vector<pair<int, int>> res;

int GetHash(int u, int v, int p, int q, int preHash[N][N], int powB1[], int powB2[], int MOD)
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

void Init(int preHash[N][N], int powB1[], int powB2[], int MOD)
{
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
            int t1 = ( 1ll * preHash[i - 1][j] * B1 ) % MOD;
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
}

Hash Get(int i, int j)
{
    int x = GetHash(i + a - 1, j + b - 1, i, j, preHashA, powB1A, powB2A, MODA);
    int y = GetHash(i + a - 1, j + b - 1, i, j, preHashB, powB1B, powB2B, MODB);
    int z = GetHash(i + a - 1, j + b - 1, i, j, preHashC, powB1C, powB2C, MODC);

    return Hash {x, y, z};
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

    Init(preHashA, powB1A, powB2A, MODA);
    Init(preHashB, powB1B, powB2B, MODB);
    Init(preHashC, powB1C, powB2C, MODC);

    for (int i = 1; i <= m - a + 1; i++)
    {
        for (int j = 1; j <= n - b + 1; j++)
        {
            cntHash[Get(i, j)]++;
        }
    } 

    int ma = 0;
    Hash k;

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
            Hash val = Get(i, j);
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