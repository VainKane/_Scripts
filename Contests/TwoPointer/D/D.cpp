#include <bits/stdc++.h>

using namespace std;

int m;
int n;

int matrix[409][409];

int lengtha[409][409];
int lengthb[409][409];

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

            lengtha[i][j] = la;
            lengthb[i][j] = lb;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a = lengtha[i][j];
            int b = lengthb[i][j];

            int maxArea = 0;

            int preb = b;
            int prea = a;

            int la = 0;
            int lb = 0;

            for (int k = i; k < i + lengtha[i][j]; k++)
            {
                // la
                // preb
                if (lengthb[k][j] < preb)
                {
                    la = 0;
                    preb = lengthb[k][j];
                }
                else
                {
                    la++;
                }

                if (maxArea < la * preb)
                {
                    maxArea = la * preb;
                }
            }

            if (maxArea < lengtha[i][j] * preb)
            {
                maxArea = lengtha[i][j] * preb;
            }

            for (int k = j; k < j + lengthb[i][j]; k++)
            {
                // lb
                // prea

                if (lengtha[i][k] < prea)
                {
                    lb = 0;
                    prea = lengtha[i][k];
                }
                else
                {
                    lb++;
                }
                if (maxArea < lb * prea)
                {
                    maxArea = lb * prea;
                }
            }

            if (maxArea < lengthb[i][j] * prea)
            {
                maxArea = lengthb[i][j] * prea;
            }

            cout << maxArea << ' ';
        }

        cout << '\n';
    }

    return 0;
}
