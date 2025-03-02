#include <bits/stdc++.h>

using namespace std;

int n;
int a[309];

set<int> res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    res.insert(0);

    for (int i = 1; i <= n; i++)
    {
        set<int> tmp;

        for (auto s : res)
        {
            tmp.insert(s + a[i]);
        }

        res.insert(tmp.begin(), tmp.end());
    }

    return 0;
}