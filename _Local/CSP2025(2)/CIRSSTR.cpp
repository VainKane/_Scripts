#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define MK(i) (1 << (i))
#define name "CIRSSTR"

// int const N = 1e5 + 5;

string s1, s2;

int n, m;
bool mark[30];

set<string> visited;
int res = 0;

void Init()
{
    s1 = " " + s1 + s1;
    s2 = " " + s2 + s2;

    n = s1.size() - 1;
    m = s2.size() - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> s1 >> s2;
   
    Init();

    FOR(i, 1, n)
    {
        memset(mark, false, sizeof mark);
        string str = "";
        
        FOR(j, i, n)
        {
            int k = s1[j] - 'a';
            if (mark[k]) break;
            
            mark[k] = true;
            str += s1[j];

            visited.insert(str);
        }
    }

    FOR(i, 1, m)
    {
        memset(mark, false, sizeof mark);
        string str = "";

        FOR(j, i, m)
        {
            int k = s2[j] - 'a';
            if (mark[k]) break;
            
            mark[k] = true;
            str += s2[j];

            if (visited.count(str)) res = max(res, (int)str.size());
        }
    }

    cout << res;

    return 0;
}