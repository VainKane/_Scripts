#include <bits/stdc++.h>

using namespace std;

int const M = 1e6 + 10;

string s;
long long res = 0;

int cntLower[M];
int cntUpper[M];
int cntNum[M];

bool Check(int l, int r)
{
    bool c1 = (cntLower[r] - cntLower[l - 1] > 0);
    bool c2 = (cntUpper[r] - cntUpper[l - 1] > 0);
    bool c3 = (cntNum[r] - cntNum[l - 1] > 0);

    return (c1 && c2 && c3 && (r - l >= 7));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        cntLower[i] = cntLower[i - 1];
        cntUpper[i] = cntUpper[i - 1];
        cntNum[i] = cntNum[i - 1];

        if (islower(s[i])) cntLower[i]++;
        if (isupper(s[i])) cntUpper[i]++;
        if (s[i] >= '0' && s[i] <= '9') cntNum[i]++;
    }

    int l = 0;
    int r = 7;

    while (l <= r && r < s.length() && l < s.length())
    {
        if (Check(l, r))
        {
            res += 1ll * s.length() - r;
            l++;
        }
        else
        {
            r++;
        }
    }

    cout << res;

    return 0;
}