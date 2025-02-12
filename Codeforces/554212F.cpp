#include <bits/stdc++.h>

using namespace std;

bool IsEqual(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first && a.second == b.second) return true;
    if (a.first == b.second && a.second == b.first) return true;

    return false;
}

bool Check(pair<int, int> p[], int u, int v)
{
    int a = p[u].first;
    int b = p[u].second;

    vector<int> c;

    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            if (i != u && i != v && j != u && j != v)
            {
                if (IsEqual(p[i], p[j]))
                {
                    sort(c.begin(), c.end());

                    if (p[i].first == a || p[i].second == a)
                    {
                        if (!binary_search(c.begin(), c.end(), i))
                        {
                            c.push_back(i);
                        }
                    }
                    if (p[i].first == b || p[i].second == b)
                    {
                        if (!binary_search(c.begin(), c.end(), i))
                        {
                            c.push_back(i);
                        }
                    }
                }
            }
        }
    }

    if (c.size() >= 2) 
    {
        for (int j = 0; j < c.size(); j++)
        {
            a = p[c[j]].first;
            b = p[c[j]].second;

            for (int i = j + 1; i < c.size(); i++)
            {
                if ((p[c[i]].first == a || p[c[i]].second == a) || (p[c[i]].first == b || p[c[i]].second == b))
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}

pair<int, int> p[6];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 6; i++)
    {
        cin >> p[i].first >> p[i].second;
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            if (IsEqual(p[i], p[j]))
            {
                if (Check(p, i, j))
                {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }

    cout << "NO";
    
    return 0;
}