#include <bits/stdc++.h>

using namespace std;

int n;

int res = 0;

map<pair<int, int>, bool> visisted;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    while (n--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = x1; i < x2; i++)
        {
            for (int j = y1; j < y2; j++)
            {
                if (!visisted.count(make_pair(i, j)))
                {
                    visisted[make_pair(i, j)] = true;
                }
            }
        }
    }

    cout << visisted.size();

    return 0;
}