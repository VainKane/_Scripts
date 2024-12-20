#include <bits/stdc++.h>

using namespace std;

int n;
int nums[102][102];

long long dig[202];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> nums[i][j];
        }
    }

    for (int i = 0; i < 2 * n - 1; i++)
    {
        dig[i] = 0;
    }


    for (int i = 0; i < 2 * n - 1; i++)
    {
        if (i <= n - 1)
        {
            for (int j = 0; j <= i; j++)
            {
                dig[i] += nums[n - 1 - j][i - j];
            }

        }
        else
        {
            for (int j = 1; j <= 2 * n - i - 1; j++)
            {
                int a = i - n + j;
                int b = j - 1;
                int n = nums[b][a];
                dig[i] += nums[j - 1][i - n + j];
            }

            cout << dig[i] << '\n';
        }
    }
}