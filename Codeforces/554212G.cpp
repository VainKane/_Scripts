#include <bits/stdc++.h>

using namespace std;

int ToInt(string s)
{
    int res = 0;

    for (char chr : s)
    {
        res *= 10;
        res += chr - '0';
    }

    return res;
}

int Cal(string s, int n)
{
    int res = 0;

    for (int i = s.length() - 1; i > 0; i--)
    {
        if (s[i] - '0' >= n)
        {
            res += ToInt(s.substr(0, i)) + 1;
        }
        else if (s[i - 1] > '0')
        {
            s[i - 1] -= 1;
            res += ToInt(s.substr(0, i)) + 1;
            s[i - 1] += 1;
        }
    }

    // if (n >= )

    return res;
}

string a;
string b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a;

    cout << Cal(a, 1);

    return 0;
}