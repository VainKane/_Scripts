#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

int const N = 40;

int n;
string s[N];

int a[N];
int cnt[N];

vector<int> adj[N];
bool visited[N];

int res = 0;

bool Equal(string a, string b)
{
    if (a.size() != b.size()) return false;
    FOR(i, 1, a.size()) if (a[i] != b[i] && a[i] != '*' && b[i] != '*') return false;
    return true;
}

bool cmp(int a, int b)
{
    return cnt[a] > cnt[b];
}

void DFS(int u)
{
    visited[u] = true;
    for (auto v : adj[u]) if (!visited[v]) DFS(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> s[i];

    FOR(i, 1, n) FOR(j, 1, n) if (i != j) cnt[i] += Equal(s[i], s[j]);

    FOR(i, 1, n) a[i] = i;
    sort(a + 1, a + n + 1, cmp);

    FOR(i, 1, n) FOR(j, i + 1, n) if (Equal(s[j], s[i])) adj[j].push_back(j);
    FORD(i, n, 1) if (!visited[i])
    {
        DFS(i);
        res++;
    }

    cout << res;

    return 0;
}