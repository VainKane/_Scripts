#include <bits/stdc++.h>

using namespace std;

int const N = 39;

int n, k, m;
int t;

long long f[N][N];
int b[N];
int p[N];

void Init()
{
    for (int x = 1; x <= min(m, n); x++) f[1][x] = 1;

    for (int i = 2; i <= k; i++)
    {
        for (int x = 1; x <= n; x++)
        {
            for (int z = 1; z <= min(x - 1, m); z++)
            {
                f[i][x] += f[i - 1][x - z];
            }
        }
    }

    cout << f[k][n] << '\n';
}

void Solve(string s)
{
    long long res = 1;
    int cnt = 0;
    int l = 1;

    s += " ";

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1]) l++;
        else
        {
            b[++cnt] = l;
            l = 1;
        }
    }

    for (int i = 1; i <= k; i++) p[i] = p[i - 1] + b[i];

    for (int i = k; i >= 1; i++)
    {
        if (i & 1)
        {
            
        } 
        else
        {
            
        }
    }

    cout << res << '\n';
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> m;
    cin >> t;

    Init();

    while (t--)
    {
        string s;
        cin >> s;
        Solve(s);               
    }

    return 0;
}