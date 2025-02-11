#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second) return true;
    else if (a.second == b.second) return a.first > b.first;
    return false;
}

int n;

pair<int, int> p[109];
int x[109];

set<int> per;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        per.insert(i + 1);

        int val;
        cin >> val;
        p[i].first = i;
        p[i].second = val;
    }

    sort(p, p + n, cmp);

    for (int i = 0; i < n; i++)
    {
        int a = max(n - p[i].second, *per.rbegin());

        if (per.count(a) != 0) x[p[i].first] = a;
        else x[p[i].first] = *per.rbegin();

        per.erase(x[p[i].first]);

        for (int val : per) cout << val << ' ';
        cout << '\n';
    }

    for (int i = 0; i < n; i++) cout << x[i] << ' ';

    return 0;
}