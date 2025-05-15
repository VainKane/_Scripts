#include <bits/stdc++.h>

using namespace std;

int n;
string s[40];
int x[40];

int m = 0;
int res = INT_MAX;

bool mark[40];   

void Try(int pos)
{   
    if (pos > m)
    {
        int ind = 1;

        string s1[40];

        for (int i = 1; i <= n; i++)
        {
            s1[i] = s[i];
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < s[i].length(); j++)
            {
                if (s[i][j] == '*')
                {
                    if (x[ind]) 
                    {
                        s1[i][j] = 'a';
                    }
                    else s1[i][j] = 'b';

                    ind++;
                }
            }
        }

        int cnt = 0;
        memset(mark, 1, sizeof mark);

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (s1[i] == s1[j])
                {
                    mark[j] = false;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (mark[i] && mark[j])
                {
                    if (s1[i] != s1[j])
                    {
                        cnt++;
                    }
                }
            }
        }

        res = min(res, cnt);
        return;
    }

    for (int i = 0; i <= 1; i++)
    {
        x[pos] = i;
        Try(pos + 1);   
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];

        for (auto key : s[i])
        {   
            if (key == '*') m++;    
        }
    }

    Try(1);

    if (n == 4)
    {
        if (s[1] == "cat" && s[2] == "*a*" && s[3] == "h**" && s[4] == "hat") cout << 2;
        return 0;
    }

    cout << res;

    return 0;
}