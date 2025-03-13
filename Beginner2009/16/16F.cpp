#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 10;

int n;
string s = "";
vector<string> back;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char t, x;
        cin >> t >> x;

        if (t == 'T')
        {
            back.push_back(s);
            s += x;
        }
        else if (t == 'U')
        {
            x -= '0';
        }
        else
        {
            x -= '0';
            cout << s[x] << '\n';
        }

        // cout << i << ' ' << s << '\n';
    }

    return 0;
}