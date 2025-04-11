#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define fi first
#define se second

int const N = 1e5 + 5;

int n;

int a[N];
pii bit[N];
vector<int> b;

void Update(int idx, int val)
{
    int pos = idx;
    while (idx <= n)
    {
        if (bit[idx].fi < val)
        {
            bit[idx].fi = val;
            bit[idx].se = pos;
        }
        idx += idx & -idx;
    }
}

int GetMax(int idx)
{
    int res = 0;

    while (idx)
    {
        res = max(res, bit[idx].fi);
        idx -= idx & -idx;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b.push_back(a[i]);
    }

    sort(all(b));
    b.erase(unique(all(b)), b.end());

    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
    }

    for (int i = 1; i <= n; i++)
    {
        Update(a[i], GetMax(a[i] - 1) + 1);
    }

    cout << GetMax(n) << '\n';
    
    vector<int> mark;
    

    return 0;
}