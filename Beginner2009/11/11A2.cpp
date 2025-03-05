#include <bits/stdc++.h>

using namespace std;

int n;
int a[309];

vector<int> res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    res.push_back(0);

    for (int i = 1; i <= n; i++)
    {
        unordered_set<int> tmp;
        tmp.insert(res.begin(), res.end());

        for (auto s : tmp)
        {
            res.push_back(s + a[i]);
        }

        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
    }   

    for (auto val : res) cout << val << ' ';

    return 0;
}