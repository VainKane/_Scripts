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

int const N = 1009;
int const K = 55;

int n, m, k;
int lb[N], rb[N], c[N];

int dp[2 * N][K];
int cnt[2 * N][2 * N];
int pre[2 * N][2 * N][K];

vector<int> id[2 * N];

void Compress()
{
    vector<int> vals;
    
    FOR(i, 1, n)
    {
        vals.push_back(lb[i]);
        vals.push_back(rb[i]);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    #define GetId(x) (lower_bound(all(vals), (x)) - vals.begin() + 1)

    FOR(i, 1, n) 
    {
        lb[i] = GetId(lb[i]);
        rb[i] = GetId(rb[i]);
    }

    m = sz(vals);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) 
    {
        cin >> lb[i] >> rb[i] >> c[i];
        rb[i] += lb[i] - 1;
    }

    Compress();
    FOR(i, 1, n) id[rb[i]].push_back(i);

    FOR(l, 1, m) 
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        FOR(r, l, m)
        {
            for (auto &i : id[r]) if (lb[i] >= l) 
            {
                pq.push(c[i]);
                if (sz(pq) > k) pq.pop();
            }

            vector<int> v;
            while (!pq.empty())
            {
                int x = pq.top(); pq.pop();
                v.push_back(x);
            }

            for (auto &x : v) 
            {
                cnt[l][r]++;
                pq.push(x);
            }

            reverse(all(v));
            FOR(i, 1, cnt[l][r]) pre[l][r][i] = pre[l][r][i - 1] + v[i - 1];
        }
    }

    FOR(r, 1, m) FOR(j, 1, k)
    {
        dp[r][j] = dp[r - 1][j];
        FOR(l, 1, r) FOR(x, 1, min(j, cnt[l][r])) maxi(dp[r][j], dp[l - 1][j - x] + pre[l][r][x]);
    }

    cout << dp[m][k];

    return 0;
}