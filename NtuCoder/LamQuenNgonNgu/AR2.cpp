#include <bits/stdc++.h>

using namespace std;

int n;
long long value;
long long res;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value;

        if (value > res)
        {
            res = value;
        }
    }

    cout << res;
}