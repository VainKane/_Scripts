#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second) return true;
    else if (a.second == b.second) return a.first > b.first;
    return false;
}

int n;
int p[109];

set<int> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        
    }

    return 0;
}