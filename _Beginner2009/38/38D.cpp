#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 5;

string t;
string p;

int n, m;
int lastA[N], lastB[N];
int a[200], b[200];

int c[2 * N];
int z[2 * N];

vector<int> res;

void Init()
{
    t = " " + t;
    p = " " + p;

    n = t.size() - 1;
    m = p.size() - 1;

    for (int i = 1; i <= n; i++)
    {
        if (lastA[t[i]]) a[i] = i - lastA[t[i]];
        lastA[t[i]] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        if (lastB[p[i]]) b[i] = i - lastB[p[i]];
        lastB[p[i]] = i;
    }

    for (int i = 1; i <= m; i++) c[i] = b[i];
    c[m + 1] = -1;
    for (int i = 1; i <= n; i++) c[m + 1 + i] = a[i];
}

void Z()
{
    int l = 0;
    int r = 0;

    for (int i = 2; i <= m + n + 1; i++)
    {
        if (i <= r) z[i] = min(z[i - l + 1], r - i + 1);
        while (i + z[i] <= m + n + 1 && (c[z[i] + i] == c[z[i] + 1] || (c[z[i] + 1] == 0 && c[z[i] + i] > z[i] + 1)))
        {
            // if (i == 13 + m + 1) cout << "13: " << z[i] << ' ';
            z[i]++;
        }
        // if (i == 13 + m + 1) cout << z[i] << ' ';

        if (r < i + z[i] - 1)
        {
            l = i;
            r = i + z[i] - 1;
        }

        if (z[i] == m) res.push_back(i - m - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t >> p;
   
    Init();
    // for (int i = 1; i <= m + n + 1; i++) cout << c[i] << ' ';
    // cout << '\n';

    Z();

    cout << res.size() << '\n';
    for (auto val : res) cout << val << ' ';
    
    // cout << '\n';
    // cout << z[13 + m + 1];

    return 0;
}