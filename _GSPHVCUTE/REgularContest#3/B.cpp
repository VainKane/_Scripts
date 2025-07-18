#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second
#define name "longtrip"

int const N = 55;

int n, m;

struct Matrix
{
    bool x[N][N];

    Matrix()
    {
        memset(x, 0, sizeof x);
    }

    static Matrix I()
    {
        Matrix res;
        FOR(i, 1, n) res.x[i][i] = 1;
        return res;
    }

    Matrix operator * (Matrix const other) const
    {
        Matrix res = Matrix::I();

        FOR(i, 1, n) FOR(j, 1, n) FOR(k, 1, n)
            res.x[i][j] |= (x[i][k] & other.x[k][j]);

        return res;
    }
};

Matrix PowMod(Matrix a, long long b)
{
    Matrix res = Matrix::I();

    while (b)
    {
        if (b & 1) res = res * a;
        
        b >>= 1;
        a = a * a;
    }

    return res;
}

long long t;
vector<pair<int, int>> adj[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> t;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Matrix T, B;

    FOR(u, 1, n) for (auto e : adj[u]) T.x[u][e.F] = true;
    B.x[1][1] = true; 

    Matrix res = PowMod(T, t - 1) * B;
    cout << (res.x[n][1] ? "Possible" : "Impossible");

    return 0;
}