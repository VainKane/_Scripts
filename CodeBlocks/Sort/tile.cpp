#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b)
{
    if (a > b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

long long Min(long long a, long long b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int n;
int bricks[100005];

long long length = 0;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> bricks[i];
    }

    sort(bricks, bricks + n);

    length = bricks[0] + 1;

    for (int i = 1; i < n; i++)
    {
        if (bricks[i] + i <= length)
        {
            length = bricks[i] + i + 1;
        }
    }

    cout << length;
}