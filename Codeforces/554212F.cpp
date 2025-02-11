#include <bits/stdc++.h>

using namespace std;

bool Check1(pair<int, int> a, pair<int, int> b)
{
    return (a.first == b.first && a.second == b.second);
}

bool Check2(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d)
{
    int x = a.first;
    int y = a.second;

    int cntx = 1;
    int cnty = 1;

    if (b.first == x || b.second) cntx++;
    if (c.first == x || c.second) cntx++;
    if (d.first == x || d.second) cntx++;

    if (b.first == y || b.second) cnty++;
    if (c.first == y || c.second) cnty++;
    if (d.first == y || d.second) cnty++;

    return (cntx == 4 || cnty == 4);
}

pair<int, int> p[6];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 6; i++)
    {
        int x;
        int y;

        cin >> x >> y;

        p[i].first = min(x, y);
        p[i].second = max(x, y);
    }

    int s1 = 0;

    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            s1 += Check1(p[i], p[j]);
        }
    }

    int s2 = 0;

    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            for (int u = j + 1; u < 6; u++)
            {
                for (int v = u + 1; v < 6; v++)
                {
                    s2 += Check2(p[i], p[j], p[u], p[v]);
                }
            }
        }
    }

    if (s1 >= 3 && s2 >= 2) cout << "YES";
    else cout << "NO";

    return 0;
}