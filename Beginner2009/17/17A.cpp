#include <bits/stdc++.h>

using namespace std;

int const mod = 1e9 + 7;
int const N = 1e6 + 10;
int const B = 199;

string a;
string b;

int hashA;
int preHashB[N];
int powB[N];

int n;
int m;

int GetHash(int l, int r)
{
    return (1ll * preHashB[r] - 1ll * preHashB[l - 1] * powB[r - l + 1] + 1ll * mod * mod) % mod;
}

vector<int> res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;

    a = " " + a;
    b = " " + b;

    n = a.size() - 1;
    m = b.size() - 1;

    for (int i = 1; i <= n; i++)
    {
        hashA = ( 1ll * hashA * B + a[i] ) % mod;
    }

    powB[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        preHashB[i] = ( 1ll * preHashB[i - 1] * B + b[i] ) % mod;
        powB[i] = ( 1ll * powB[i - 1] * B ) % mod;
    }

    for (int i = 1; i <= m - n + 1; i++)
    {
        if (hashA == GetHash(i, i + n - 1))
        {
            res.push_back(i);
        }
    }

    cout << res.size() << '\n';
    for (auto val : res) cout << val << ' ';

    return 0;
}