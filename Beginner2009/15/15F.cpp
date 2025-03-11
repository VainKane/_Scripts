#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 10;

int child[N * 10][30];
bool isEnd[N * 10];

int cnt = 1;

int n;
string a[N];
string str;

int t;

void Add(string &s)
{
    int u = 1;
    for (int i = 0; i < s.size(); i++)
    {
        int k = s[i] - 'a';
        if (!child[u][k]) child[u][k] = ++cnt;
        u = child[u][k];
    }
    isEnd[u] = true;
}

string Query(string &s)
{
    sort(s.begin(), s.end());

    string res = "";
    string tmp;

    int cnt1[30];
    int cnt2[30];
    memset(cnt1, 0, sizeof cnt1);
    memset(cnt2, 0, sizeof cnt2);
    for (auto ch : s)
    {
        int k = ch - 'a';
        cnt1[k]++;
        cnt2[k]++;
    }

    int pre = 0;

    bool check = false;
    int p = 0;

    for (int i = 0; i < s.size(); i++)
    {
        tmp = "";
        tmp += s[i];
        int u = 1;

        int k = s[i] - 'a';
        for (int i = 0; i < 29; i++) cnt1[i] = cnt2[i];


        if (child[u][k] && cnt1[k])
        {
            u = child[u][k];
            cnt1[k]--;

            for (int m = 0; m < s.size(); m++)
            {
                for (int j = 0; j < s.size(); j++)
                {
                    k = s[j] - 'a';
                    if ((cnt1[k] && !check) || (check && k != p))
                    {
                        if (!child[u][k]) continue;
                        check = false;
                        pre = u;
                        u = child[u][k];
                        tmp += s[j];
                        cnt1[k]--;
                        j = -1;
    
                        if (isEnd[u] && tmp.size() > res.size()) res = tmp;
                    }
                }

                p = *tmp.rbegin() - 'a';
                check = true;
                tmp = tmp.substr(0, tmp.size() - 1);
                for (int i = 0; i < 29; i++) cnt1[i] = cnt2[i];
                for (auto ch : tmp) cnt1[ch - 'a']--;
                u = pre;    
            }
        }
    }

    if (res == "") res = "IMPOSSIBLE";

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        Add(str);
    }

    cin >> t;

    while (t--)
    {
        cin >> str;
        cout << Query(str) << '\n';
    }

    return 0;
}