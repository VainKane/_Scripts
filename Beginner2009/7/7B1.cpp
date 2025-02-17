#include <bits/stdc++.h>

using namespace std;

bool Go(int &d, pair<char, int> &pos, pair<char, int> a[], int n, set<pair<char, int>> &visisted)
{
    if (d == 0)
    {
        visisted.insert(pos);
        pos.second -= 1;

        if (visisted.count(pos) != 0)
        {
            return false;
        }
        if (binary_search(a, a + n, pos) || pos.second < 1)
        {
            pos.second += 1;
            d = 3;
            return Go(d, pos, a, n, visisted);
        }
    }
    else if (d == 1)
    {
        visisted.insert(pos);
        pos.first += 1;

        if (visisted.count(pos) != 0)
        {
            return false;
        }
        if (binary_search(a, a + n, pos) || pos.first > 'H')
        {
            pos.first -= 1;
            d -= 1;
            return Go(d, pos, a, n, visisted);
        }
    }
    else if (d == 2)
    {
        visisted.insert(pos);
        pos.second += 1;

        if (visisted.count(pos) != 0)
        {
            return false;
        }
        if (binary_search(a, a + n, pos) || pos.second > 8)
        {
            pos.second -= 1;
            d -= 1;
            return Go(d, pos, a, n, visisted);
        }
    }
    else
    {
        visisted.insert(pos);
        pos.first -= 1;

        if (visisted.count(pos) != 0)
        {
            return false;
        }
        if (binary_search(a, a + n, pos) || pos.first < 'A')
        {
            pos.first += 1;
            d -= 1;
            return Go(d, pos, a, n, visisted);
        }
    }

    return true;
}

int n;
pair<char, int> a[40];
pair<char, int> pos = make_pair('A', 1);
set<pair<char, int>> visisted;

int res = 0;
int d = 2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        a[i].first = s[0];
        a[i].second = s[1] - '0';
    }

    sort(a, a + n);

    while (Go(d, pos, a, n, visisted))
    {
        res++;
    }
    
    // for (auto val : visisted) cout << val.first << val.second << ' ';
    // cout << '\n';

    cout << res;

    return 0;
}