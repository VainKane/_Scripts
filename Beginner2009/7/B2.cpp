#include <bits/stdc++.h>

using namespace std;

int n;
int b[10][10];

pair<int, int> pos = make_pair(0, 0);

void TurnLeft();

void Go(int d, pair<int, int> pos)
{
    if (d == 0)
    {
        while (pos.first > 0)
        {
            pos.first -= 1;

            if (b[pos.first][pos.second] == 1)
            {

            }
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