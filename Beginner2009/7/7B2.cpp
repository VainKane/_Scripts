#include <bits/stdc++.h>

using namespace std;

int n;

int b[10][10];
pair<int, int> pos = make_pair(0, 0);

void TurnLeft(int &d)
{
    d -= 1;

    if (d == -1)
    {
        d = 3;
    }
}

void TurnRight(int &d)
{
    d += 2;
    d %= 3;
}

int Go(int d, pair<int, int> pos)
{
    int s = 0;

    if (d == 0)
    {
        while (pos.first > 0)
        {
            pos.first -= 1;
            s++;
            b[pos.first][pos.second] = -1;

            if (b[pos.first][pos.second] == 1|| b[pos.first - 1][pos.second] == 1)
            {
                int s1 = 0;
                int s2 = 0;

                TurnLeft(d);
                s1 = Go(d, pos);
                TurnRight(d);
                s2 = Go(d, pos);
            }
        }
    }

    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        b[s[1] - '1'][s[0] - 'A'] = true;
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << b[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}