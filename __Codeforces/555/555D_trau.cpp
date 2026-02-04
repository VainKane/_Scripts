#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 10009;

int n, m;

int x[N];
bool a[N];

int l, r;

void GoRight(int &pos, int &len)
{   
    int res = pos;

    while (len && pos < r)
    {
        len--; pos++;
        if (a[pos]) res = pos;
    }

    pos = res;    
}

void GoLeft(int &pos, int &len)
{   
    int res = pos;

    while (len && pos > l)
    {
        len--; pos--;
        if (a[pos]) res = pos;
    }

    pos = res;    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n)
    {
        cin >> x[i];
        x[i] += 5000;
        a[x[i]] = true;
    }

    l = *min_element(x + 1, x + n + 1);
    r = *max_element(x + 1, x + n + 1);

    while (m--)
    {
        int idx, len;
        cin >> idx >> len;

        idx = x[idx];

        while (len)
        {
            GoRight(idx, len);
            GoLeft(idx, len);
        }

        cout << idx - 5000 << '\n';
        // FOR(i, 1, n) if (x[i] == idx)
        // {
        //     cout << i << '\n';
        //     break;
        // }
    }

    return 0;
}