#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 2e5 + 5;

int n, q;
int a[N];

map<int, int> mp;
int pre[N];

int upMin[N][20];
int upMax[N][20];
int upPre[N][20];

void Init()
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) 
    {
        cin >> a[i];
        
        int &x = mp[a[i]];
        pre[i] = x;
        x = i;

        b[i - 1] = a[i] - a[i - 1];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
    }


    return 0;
}