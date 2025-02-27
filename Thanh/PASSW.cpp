#include <bits/stdc++.h>

using namespace std;

bool Check(string s)
{
    bool c1 = false;
    bool c2 = false;
    bool c3 = false;

    for (auto chr : s)
    {
        if (chr >= 'A' && chr <= 'Z') c1 = true;
        if (chr >= 'a' && chr <= 'z') c2 = true;
        if (chr >= '0' && chr <= '9') c3 = true;
    }

    return (c1 & c2 & c3 & (s.length() >= 8));
}

string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;

    if (s.length() <= 5009)
    {
        long long cnt = 0;
        int l = 0;
        int r = 7;
    
        while (l <= r && r < s.length() && l < s.length())
        {
            if (Check(s.substr(l, r - l + 1)))
            {
                cnt += 1ll * s.length() - r;
                l++;
            }
            else
            {
                r++;
            }
        }
    
        cout << cnt;
    }
    else
    {
        int x = 0;
        int y = 0;
        int z = 0;

        for (auto chr : s)
        {
            if (chr >= 'A' && chr <= 'Z') x++;
            if (chr >= '0' && chr <= '9') y++;
            if (chr >= 'a' && chr <= 'z') z++;
        }

        cout << 1ll * x * y * z;
    }

    return 0;
}