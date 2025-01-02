#include <bits/stdc++.h>

using namespace std;

int n;

int odd[20009];
int even[20009];

set<int> bac;
set<int> nam;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        if (value % 2 == 0)
        {
            if (even[value - 2] == 0)
            {
                even[value] = value;
            }
            else
            {
                even[value] = even[value - 2];
            }
        }
        else
        {
            if (odd[value - 2] == 0)
            {
                odd[value] = value;
            }
            else
            {
                odd[value] = odd[value - 2];
            }
        }
    }

    for (int value : odd)
    {
        if (value != 0)
        {
            bac.insert(value);
        }
    }

    for (int value : even)
    {
        if (value != 0)
        {
            nam.insert(value);
        }
    }

    cout << bac.size() << '\n';
    cout << nam.size();
}