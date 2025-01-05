#include <bits/stdc++.h>

using namespace std;

int n;
int k;
int x[109];

int nums[109];

void PrintRes()
{
    for (int i = 1; i <= k; i++)
    {
        cout << x[i];
    }

    cout << '\n';
}

void Try(int i)
{
    for (int j = i; j <= n - k + i; j++)
    {
        x[i] = nums[j];

        if (i == k)
        {
            PrintRes();
        }
        else
        {
            Try(i + 1);
        }
    }
}

int main()
{
    cin >> k >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    Try(1);
}