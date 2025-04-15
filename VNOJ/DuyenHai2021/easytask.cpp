#include <bits/stdc++.h>

using namespace std;

#define name "easytask"

int const N = 1e6 + 5;

typedef long long ll;

int n;
int a[N];
ll p[N];

bool prime[N];

vector<int> b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }

    memset(prime, 1, sizeof prime);

    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) if (prime[i]) b.push_back(i);
    cout << b.size();

    for (int i = 0; i < b.size(); i++)
    {
        for (int i = 0; i < )
    }

    return 0;
}
