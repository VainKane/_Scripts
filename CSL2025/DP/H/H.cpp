#include <bits/stdc++.h>

using namespace std;

int x[30];
int n;
int matrix[30][30];

long long res = 0;

void Res()
{
    long long sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += x[i];
    }

    if (sum > res) res = sum;
}


void Try(int i)
{
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {

        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    Try(1);

    cout << res;

    return 0;
}
