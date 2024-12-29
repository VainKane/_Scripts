#include <bits/stdc++.h>

using namespace std;

int m;
int n;

int matrix[409][409];

int main()
{
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a = i;
            int b = j;

            int la = 0;
            int lb = 0;

            while (matrix[a][j] == 0 && a < m)
            {
                a++;
                la++;
            }
            while (matrix[i][b] == 0 && b < n)
            {
                b++;
                lb++;
            }

            cout << la << ' ';
        }

        cout << '\n';
    }

    return 0;
}
