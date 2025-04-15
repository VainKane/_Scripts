#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define name "sotrungvi"

typedef long long ll;

int const N = 1e5 + 5;

vector<int> t[4 * N];

int n;
int k;
pii a[N];

ll res = 0;

void Build(int v, int l, int r)
{
    if (l == r)
    {
        t[v].pb(a[l].S);
        return;
    }

    int mid = l + (r - l) / 2;

    Build(2 * v, l, mid);
    Build(2 * v + 1, mid + 1, r);

    t[v].resize(t[2 * v].size() + t[2 * v + 1].size());
    merge(all(t[2 * v]), all(t[2 * v + 1]), t[v].begin());
}

int Get(int v, int l, int r, int left, int right, int k)
{
    if (l == r) return a[l].F;

    int mid = l + (r - l) / 2;

    auto it1 = upper_bound(all(t[2 * v]), right);
    auto it2 = lower_bound(all(t[2 * v]), left);

    if (it1 - it2 >= k) return Get(2 * v, l, mid, left, right, k);
    return Get(2 * v + 1, mid + 1, r, left, right, k - (it1 - it2));
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
        int x;
        cin >> x;

        a[i] = {x, i};
    }

    sort(a + 1, a + n + 1);
    Build(1, 1, n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int l = j - i + 1;
            if (l & 1) l = (l + 1) / 2;
            else l = (l / 2) + 1;

            if (Get(1, 1, n, i, j, l) >= k) res++;
        }
    }

    cout << res;

    return 0;
}
