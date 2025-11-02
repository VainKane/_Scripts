#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())

int const N = 1e5 + 5;

int n, m;
vector<int> s[N];
vector<int> v[N];

long long Solve1(int x, int y)
{
    long long res = 0;
    for (auto &id : v[x]) res += id * binary_search(all(s[id]), y);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int k; cin >> k;
        while (k--)
        {
            int x; cin >> x;
            s[i].push_back(x);
            v[x].push_back(i);
        }
 
        sort(all(s[i]));
        s[i].erase(unique(all(s[i])), s[i].end());
    }

    int q; cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if (sz(x) <= sqrt(1e5)) Solve1(x, y) << '\n';
        else
    }

    return 0;
}