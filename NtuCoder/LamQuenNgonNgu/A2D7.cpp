#include <bits/stdc++.h>

using namespace std;

int n;

long long matrix[102][102];

long long sum = 0;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (matrix[n - i][i - 1] % 2 == 1)
        {
            sum += matrix[n - i][i - 1];
        }
    }

    cout << sum;
}