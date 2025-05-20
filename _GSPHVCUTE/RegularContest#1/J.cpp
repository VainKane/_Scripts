#include <bits/stdc++.h>

using namespace std;

#define name "password"

int const N = 55;

int n;
int a[N];

string res = "c";

int x[N];

int cnt = 0;

void Try(int pos, int x[], string s, int ch)
{
    cnt++;
    if (pos > n)
    {
        for (int i = 1; i <= n; i++) if (x[i] != a[i]) return;
        if (s < res) res = s;
        return;
    }

    for (int l = 1; l <= n - pos + 1; l++)
    {       
        int tmp[N];
        for (int i = 1; i <= n; i++) tmp[i] = x[i];
        for (int i = 1; i <= l; i++)
        {
            tmp[i] += l - i + 1;
            if (tmp[i] > a[i]) return;
        }
        for (int i = 1; i <= l; i++) s += ch;
        ch = (ch == 'a' ? 'b' : 'a');
        Try(pos + l, tmp, s, ch);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    Try(1, x, "", 'a');
    if (res == "c") res = "No solution.";
    
    cout << res;
    cout << '\n' << cnt;

    return 0;
}