#include <bits/stdc++.h>

using namespace std;

string s;

int k;

string res = "";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    cin >> k;

    int pre = 0;

    auto i = s.begin();

    while (res.length() < s.length() - k)
    {
        int c = s.length() - 1 - (s.length() - k - res.length() - 1);
        auto it = min_element(i, s.begin() + s.length() - 1 - (s.length() - k - res.length() - 1) + 1);
        i = it + 1;

        res += *it;
    }

    cout << res;

    return 0;   
}